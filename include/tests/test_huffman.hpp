#include "huffman_pq.h"
#include "utility.h"

//根据样本文件统计各字符出现频率
std::unique_ptr<int[]>
statistics(char* sample_text_file) {
  auto freq = std::make_unique<int[]>(N_CHAR);
  //以下统计需随机访问，故以数组记录各字符出现次数
  FILE* fp = fopen(sample_text_file, "r");  //assert: 文件存在且可正确打开
  for(char ch; 0 < fscanf(fp, "%c", &ch);)  //逐个扫描样本文件中的每个字符
    if(ch >= 0x20)
      freq[ch - 0x20]++;  //累计对应的出现次数
  fclose(fp);
  return freq;
}

/*
 * 初始化Huffman森林：根据传入的频率统计表freq，为每个字符创建一棵树
 *
 * forest基于优先级队列实现，此算法适用于符合PQ接口的任何实现方式
 * 为Huffman_PQ_List、Huffman_PQ_ComplHeap和Huffman_PQ_LeftHeap共用
 * 编译前对应工程只需设置相应标志：DSA_PQ_List、DSA_PQ_ComplHeap或DSA_PQ_LeftHeap
 */
std::unique_ptr<HuffForest>
initForest(std::unique_ptr<int[]>& freq) {
  auto forest = std::make_unique<HuffForest>();
  //以PQ实现的Huffman森林
  for(int i = 0; i < N_CHAR; i++) {  //为每个字符
    //生成一棵树，并将字符集频率
    forest->push_back(std::make_unique<HuffTree>());
    forest->back()->insertAsRoot(HuffChar(0x20 + i, freq[i]));
  }
  return forest;
}

// 在Huffman森林中找出权重最小的字符
// HuffTree*
HuffForest::iterator
minHChar(std::unique_ptr<HuffForest>& forest) {
  // 从首节点出发查找
  HuffForest::iterator it = forest->begin();
  // 最小Huffman树所在的节点位置
  HuffForest::iterator min_it = it;
  // 目前最小权重
  HuffForest::size_type min_weight = (*it)->root()->data.weight;
  // 遍历所有节点
  for(; it != forest->end(); ++it) {
    if(min_weight > (*it)->root()->data.weight) {
      min_weight = (*it)->root()->data.weight;
      min_it = it;
    }
  }
  // 将挑选的Huffman树从森林中摘除
  return min_it;
}

/*
 * Huffman树构造算法：对传入的Huffman森林forest逐步合并，直到成为一棵树
 *
 * forest基于优先级队列实现，此算法适用于符合PQ接口的任何实现方式
 * 为Huffman_PQ_List、Huffman_PQ_ComplHeap和Huffman_PQ_LeftHeap共用
 * 编译前对应工程只需设置相应标志：DSA_PQ_List、DSA_PQ_ComplHeap或DSA_PQ_LeftHeap
 */
// HuffTree*
std::unique_ptr<HuffTree>
generateTree(std::unique_ptr<HuffForest>& forest) {
  std::unique_ptr<HuffTree> s1 = std::make_unique<HuffTree>();
  std::unique_ptr<HuffTree> s2 = std::make_unique<HuffTree>();
  std::unique_ptr<HuffTree> s = nullptr;
  HuffForest::iterator it;
  while(1 < forest->size()) {
    it = minHChar(forest);
    s1->insertAsRoot((*it)->root()->data);
    forest->erase(it);
    it = minHChar(forest);
    s2->insertAsRoot((*it)->root()->data);
    forest->erase(it);

    s = std::make_unique<HuffTree>();
    /*DSA*/ printf("Merging ");
    print(s1->root()->data);
    printf(" with ");
    print(s2->root()->data);
    printf(" ...\n");

    s->insertAsRoot(
      HuffChar('^', s1->root()->data.weight + s2->root()->data.weight));
    s->attachAsLC(s->root(), *s1);
    s->attachAsRC(s->root(), *s2);
    forest->emplace_back(std::move(s));  //将合并后的Huffman树插回Huffman森林
  }
  //至此，森林中的最后一棵树
  std::unique_ptr<HuffTree> ret = std::move(forest->front());
  forest->erase(forest->begin());
  return ret;
}

//通过遍历获取各字符的编码
void
generateCT(std::unique_ptr<Bitmap>& code, int length, HuffTable& table,
           BinNodePosi(HuffChar) v) {
  //若是叶节点（还有多种方法可以判断）
  if(isLeaf(v)) {
    table.put(v->data.ch,
              const_cast<char*>(code->bitsToString(length).c_str()));
    return;
  }
  //Left = 0
  if(hasLChild(v)) {
    code->clear(length);
    generateCT(code, length + 1, table, v->l_child);
  }
  //Right = 1
  if(hasRChild(v)) {
    code->set(length);
    generateCT(code, length + 1, table, v->r_child);
  }
}

//将各字符编码统一存入以散列表实现的编码表中
// HuffTable*
HuffTable
generateTable(std::unique_ptr<HuffTree>& tree) {
  HuffTable table;
  auto code = std::make_unique<Bitmap>();
  generateCT(code, 0, table, tree->root());
  return table;
};

//按照编码表对Bitmap串编码
int
encode(HuffTable& table, std::unique_ptr<Bitmap>& codeString, const char* s) {
  int n = 0;                                      //待返回的编码串总长n
  for(size_t m = strlen(s), i = 0; i < m; i++) {  //对于明文中的每个字符
    char** pCharCode = table.get(s[i]);           //取出其对应的编码串
    if(!pCharCode)
      pCharCode = table.get(s[i] + 'A' - 'a');  //小写字母转为大写
    if(!pCharCode)
      pCharCode = table.get(' ');  //无法识别的字符统一视作空格
    if(pCharCode) {
      //输出当前字符的编码
      printf("%s", *pCharCode);
      //将当前字符的编码接入编码串
      for(size_t m = strlen(*pCharCode), j = 0; j < m; j++)
        '1' == *(*pCharCode + j) ? codeString->set(n++)
                                 : codeString->clear(n++);
    }
  }
  printf("\n");
  return n;
}  //二进制编码串记录于位图codeString中

// 根据编码树对长为n的Bitmap串做Huffman解码
void
decode(std::unique_ptr<HuffTree>& tree, std::unique_ptr<Bitmap>& code, int n) {
  BinNodePosi(HuffChar) x = tree->root();
  for(int i = 0; i < n; i++) {
    x = code->test(i) ? x->r_child : x->l_child;
    if(isLeaf(x)) {
      printf("%c", x->data.ch);
      x = tree->root();
    }
  }
  /*DSA*/ if(x != tree->root())
    printf("...");
  printf("\n");
}  //解出的明码，在此直接打印输出；实用中可改为根据需要返回上层调用者