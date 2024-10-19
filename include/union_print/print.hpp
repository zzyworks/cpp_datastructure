#ifndef PRINT_HPP
#define PRINT_HPP

#include <cstdio>
#include <iostream>
#include "avl.hpp"       //AVL树
#include "bin_tree.hpp"  //二叉树
#include "bitmap.h"
#include "bst.hpp"      //二叉搜索树
#include "huff_char.h"  //Huffman超字符
#include "utility.h"
// #include "../Splay/Splay.h" //伸展树
// #include "../redBlack/RedBlack.h" //红黑树
// #include "../BTree/BTree.h" //二叉搜索树
#include "entry.hpp"  //词条
// #include "../Skiplist/Quadlist.h" //四叉表
// #include "../Skiplist/Skiplist.h" //跳转表
#include "hash_table.hpp"  //散列表
// #include "../PQ_List/PQ_List.h" //基于列表实现的优先级队列
#include "pq_compl_heap.hpp"  //基于完全堆实现的优先级队列
// #include "../PQ_LeftHeap/PQ_LeftHeap.h" //基于左式堆实现的优先级队列
#include "graph.hpp"         //图
#include "graph_matrix.hpp"  //基于邻接矩阵实现的图

#define ROOT 0
#define L_CHILD 1
#define R_CHILD -1 * L_CHILD

#define MSG(value, msg)                                                 \
  std::cout << "(__FILE__ = " << __FILE__                               \
            << ", __FUNCTION__ = " << __FUNCTION__                      \
            << ", __LINE__ = " << __LINE__ << "): " << (msg) << (value) \
            << "\n";

/*
 * 数据元素、数据结构通用输出接口
 */
template<typename T>
static void print(T* x);

template<typename T>
static void print(T&& x);

// for Stack
template<typename T>
static void print(const T& x);

// 字符串特别处理
static void print(char* x);

// 字符串特别处理
static void print(const char* x);

/*
 * 二叉树各种派生类的统一打印
 */
template<typename T>  //元素类型
static void
printBinTree(BinNodePosi(T) bt, int depth, int type,
             std::unique_ptr<Bitmap>& bType) {
  if(!bt)
    return;
  if(-1 < depth)  //设置当前层的拐向标志
    R_CHILD == type ? bType->set(depth) : bType->clear(depth);
  printBinTree(bt->r_child, depth + 1, R_CHILD, bType);  //右子树（在上）
  print(bt);
  printf(" *");
  for(int i = -1; i < depth; i++)  //根据相邻各层
    if((0 > i)
       || bType->test(i) == bType->test(i + 1))  //的拐向是否一致，即可确定
      printf("      ");                          //是否应该
    else
      printf("│    ");  //打印横线
  switch(type) {
    case R_CHILD:
      printf("┌─");
      break;
    case L_CHILD:
      printf("└─");
      break;
    default:
      printf("──");
      break;  //root
  }
  print(bt);
#if defined(DSA_HUFFMAN)
  if(IsLeaf(*bt))
    bType->print(depth + 1);  //输出Huffman编码
#endif
  printf("\n");
  printBinTree(bt->l_child, depth + 1, L_CHILD, bType);  //左子树（在下）
}

/*
 * 递归打印输出
 */
template<typename T>  //元素类型
static void
printComplHeap(const PQComplHeap<T>& elem, int n, int k, int depth, int type,
               int* bType) {
  if(k >= n)
    return;  //递归基
  bType[depth] = type;
  printComplHeap(elem, n, RChild(k), depth + 1, R_CHILD,
                 bType);  //右子树（在上）
  print(elem[k]);
  (0 < k) && (elem[Parent(k)] < elem[k]) ? printf("X") : printf(" ");
  printf("*");
  for(int i = 0; i < depth; i++)  //根据相邻各层
    if(bType[i] + bType[i + 1])   //的拐向是否一致，即可确定
      printf("      ");           //是否应该
    else
      printf("│    ");  //打印横线
  switch(type) {
    case R_CHILD:
      printf("┌─");
      break;
    case L_CHILD:
      printf("└─");
      break;
    default:
      printf("──");
      break;  //root
  }
  print(elem[k]);
  (0 < k) && (elem[Parent(k)] < elem[k]) ? printf("X") : printf(" ");
  printf("\n");
  printComplHeap(elem, n, LChild(k), depth + 1, L_CHILD,
                 bType);  //左子树（在下）
}

struct UnionPrint {
  /*
 * 基本类型
 */
  static void p(int e) { printf(" %04d", e); }

  static void p(float e) { printf(" %4.1f", e); }

  static void p(double e) { printf(" %4.1f", e); }

  static void p(char e) { printf(" %c", (31 < e) && (e < 128) ? e : '$'); }

  /*
 * Huffman（超）字符
 */
  static void p(HuffChar& e) { printf("[%c]:%-5d", e.ch, e.weight); }

  // 图的顶点状态
  static void p(VStatus e) {
    switch(e) {
      case VStatus::UNDISCOVERED:
        printf("U");
        break;
      case VStatus::DISCOVERED:
        printf("D");
        break;
      case VStatus::VISITED:
        printf("V");
        break;
      default:
        printf("X");
        break;
    }
  }

  // 图边的类型
  static void p(EType e) {
    switch(e) {
      case EType::UNDETERMINED:
        printf("U");
        break;
      case EType::TREE:
        printf("T");
        break;
      case EType::CROSS:
        printf("C");
        break;
      case EType::BACKWARD:
        printf("B");
        break;
      case EType::FORWARD:
        printf("F");
        break;
      default:
        printf("X");
        break;
    }
  }

  /*
 * Entry
 */
  template<typename K, typename V>
  static void p(Entry<K, V>& e) {
    printf("-<");
    print(e.base.first);
    printf(":");
    print(e.base.second);
    printf(">-");
  }

  /*
 * BinTree节点
 */
  template<typename T>
  static void p(BinNode<T>& node) {
    p(node.data);  //数值
                   /*
    * height & NPL
    */
#if defined(DSA_LEFTHEAP)
    printf("(%-2d)", node.npl);  //NPL
#elif defined(DSA_BST)
    printf("(%-2d)", node.height);  //高度
#elif defined(DSA_AVL)
    printf("(%-2d)", node.height);                 //高度
#elif defined(DSA_REDBLACK)
    printf("(%-2d)", node.height);                       //高度
#elif defined(DSA_SPLAY)
    printf("(%-2d)", node.height);  //高度
#endif
    /*
    * 父子链接指针
    */
    printf(((node.l_child && &node != node.l_child->parent)
            || (node.r_child && &node != node.r_child->parent))
             ? "@"
             : " ");
    /******************************************************************************************
    * 节点颜色
    ******************************************************************************************/
#if defined(DSA_REDBLACK)
    printf(node.color == RB_BLACK ? "B" : " ");  //（忽略红节点）
#endif
    /******************************************************************************************
    * 父子（黑）高度、NPL匹配
    ******************************************************************************************/
#if defined(DSA_PQ_COMPLHEAP)
    //高度不必匹配
#elif defined(DSA_PQ_LEFTHEAP)
    printf(                         //NPL
      (node.rc && node.npl != 1 + node.rc->npl)
          || (node.lc && node.npl > 1 + node.lc->npl)
        ? "%%"
        : " ");
#elif defined(DSA_REDBLACK)
    printf(BlackHeightUpdated(node) ? " " : "!");  //黑高度
#else
    printf(heightUpdated(node.selfNode()) ? " " : "!");  //（常规）高度
#endif
    /******************************************************************************************
    * 左右平衡
    ******************************************************************************************/
#if defined(DSA_AVL)
    if(!AvlBalanced(node))
      printf("X");  //AVL平衡
    else if(0 < BalFac(node))
      printf("\\");  //AVL平衡
    else if(BalFac(node) < 0)
      printf("/");  //AVL平衡
    else
      printf("-");  //AVL平衡
#elif defined(DSA_REDBLACK)
    if(!Balanced(node))
      printf("X");  //RB平衡
    else if(0 < BalFac(node))
      printf("\\");  //RB平衡
    else if(BalFac(node) < 0)
      printf("/");  //RB平衡
    else
      printf("-");  //RB平衡
#else
                                                   //平衡无所谓
#endif
  }

  /*
 * 基础BinTree
 */
  template<typename T>
  static void p(BinTree<T>& bt) {
    printf("%s[%d]*%d:\n", typeid(bt).name(), &bt, bt.size());  //基本信息
    //记录当前节点祖先的方向
    std::unique_ptr<Bitmap> branchType = std::make_unique<Bitmap>();
    printBinTree(bt.root(), -1, ROOT, branchType);  //树状结构
    printf("\n");
  }

  // template<typename T>
  // static void p(BTree<T>&);  //B-树

  /*
 * 基于BinTree实现的BST
 */
  template<typename T>
  static void p(BST<T>& bt) {
    printf("%s[%d]*%d:\n", typeid(bt).name(), (std::size_t)&bt, bt.size());
    //记录当前节点祖先的方向
    std::unique_ptr<Bitmap> branchType = std::make_unique<Bitmap>();
    //树状结构
    printBinTree(bt.root(), -1, ROOT, branchType);
    printf("\n");
  }

  /*
 * 基于BST实现的AVL
 * 其中调用的BinNode的打印例程，可以显示BF状态
 */
  template<typename T>
  static void p(AVL<T>& avl) {
    printf("%s[%ld]*%d:\n", typeid(avl).name(), (std::size_t)&avl, avl.size());
    //记录当前节点祖先的方向
    std::unique_ptr<Bitmap> branchType = std::make_unique<Bitmap>();
    //树状结构
    printBinTree(avl.root(), -1, ROOT, branchType);
    printf("\n");
  }

  // template<typename T>
  // static void p(RedBlack<T>&);  //RedBlack
  // template<typename T>
  // static void p(Splay<T>&);  //Splay
  // template<typename T>
  // static void p(Quadlist<T>&);  //Quadlist
  // template<typename K, typename V>
  // static void p(Skiplist<K, V>&);  //Skiplist

  //Hashtable
  template<typename K, typename V>
  static void p(Hashtable<K, V>& ht) {
    printf("%s[%d]*%d/%d:\n", typeid(ht).name(), &ht, ht.size_,
           ht.capacity_);                  //基本信息
    for(int i = 0; i < ht.capacity_; i++)  //输出桶编号
      printf("  %4d  ", i);
    printf("\n");
    for(int i = 0; i < ht.capacity_; i++)  //输出所有元素
      if(ht.ht_[i])
        printf("-<%04d>-", ht.ht_[i]->base.first);  //演示用，仅适用于int
      else if(ht.lazy_removal_->test(i))
        printf("-<xxxx>-");
      else
        printf("--------");
    printf("\n");
    for(int i = 0; i < ht.capacity_; i++)  //输出所有元素
      if(ht.ht_[i])
        printf("    %c   ", ht.ht_[i]->base.second);  //演示用，仅适用于char
      //      if (ht.ht[i]) printf("%8s", ht.ht[i]->value); //针对Huffman编码中使用的散列表
      else if(ht.lazy_removal_->test(i))
        printf(" <xxxx> ");
      else
        printf("        ");
    printf("\n");
  }

  // template<typename T>
  // static void p(PQ_List<T>&);  //PQ_List

  /*
 * 打印输出PQComplHeap
 */
  template<typename T>
  static void p(PQComplHeap<T>& pq) {
    printf("%s[%p]*%d:\n", typeid(pq).name(), &pq, pq.size());
    //最深256层 <= 2^256 = 1.16*10^77
    int branchType[256];
    //树状结构
    printComplHeap(pq, pq.size(), 0, 0, ROOT, branchType);
    printf("\n");
  }

  // template<typename T>
  // static void p(PQ_LeftHeap<T>&);  //PQ_LeftHeap

  // Edge对象
  template<typename ET>
  static void p(Edge<ET>& e) {
    printf("data=%d, weight=%d", e.data, e.weight);
    UnionPrint::p(e.type);
  }

  /*
 * 图Graph
 */
  template<typename Tv, typename Te>
  static void p(GraphMatrix<Tv, Te>& s) {
    int inD = 0;
    for(int i = 0; i < s.vertexCount(); i++)
      inD += s.inDegree(i);
    int outD = 0;
    for(int i = 0; i < s.vertexCount(); i++)
      outD += s.outDegree(i);
    //基本信息
    printf("%s[%d]*(%d, %d):\n", typeid(s).name(), &s, s.vertexCount(),
           s.edgeCount());
    // 标题行
    print(s.vertexCount());
    printf(" ");
    print(inD);
    printf("|");
    for(int i = 0; i < s.vertexCount(); i++) {
      print(s.vertex(i));
      printf("[");
      print(s.status(i));
      printf("] ");
    }
    printf("\n");
    // 标题行（续）
    print(outD);
    printf(" ");
    print(s.edgeCount());
    printf("|");
    for(int i = 0; i < s.vertexCount(); i++) {
      print(s.inDegree(i));
      printf(" ");
    }
    printf("| dTime fTime Parent Weight\n");
    // 水平分隔线
    printf("-----------+");
    for(int i = 0; i < s.vertexCount(); i++)
      printf("------");
    printf("+----------------------------\n");
    // 逐行输出各顶点
    for(int i = 0; i < s.vertexCount(); i++) {
      print(s.vertex(i));
      printf("[");
      print(s.status(i));
      printf("] ");
      print(s.outDegree(i));
      printf("|");
      for(int j = 0; j < s.vertexCount(); j++)
        if(s.exists(i, j)) {
          print(s.edge(i, j));
          print(s.type(i, j));
        } else
          printf("     .");
      printf("| ");
      print(s.dTime(i));
      printf(" ");
      print(s.fTime(i));
      printf("     ");
      if(0 > s.parent(i))
        print("^");
      else
        print(s.vertex(s.parent(i)));
      printf("  ");
      if(INT_MAX > s.priority(i))
        print(s.priority(i));
      else
        print(" INF");
      printf("\n");
    }
    printf("\n");
  }

  //向量、列表等支持traverse()遍历操作的线性结构
  template<typename T>
  static typename std::enable_if<!is_smart_pointer<T>::value, void>::type p(
    T& s) {
    printf("%s[%d]*%d:\n", typeid(s).name(), &s, s.size());  // 基本信息
    s.traverse(print);  // 通过print()遍历输出所有元素
    printf("\n");
  }

  // 智能指针
  template<typename T>
  static typename std::enable_if<is_smart_pointer<T>::value, void>::type p(
    T& s) {
    s ? p(*s) : print("<NULL>");
  }

  // 普通指针
  template<typename T>
  static void p(T* s) {
    s ? p(*s) : print("<NULL>");
  }
};  // UniPrint

template<typename T>
static void
print(T* x) {
  x ? print(*x) : print(" <NULL>");
}

template<typename T>
static void
print(T&& x) {
  UnionPrint::p(std::forward<T>(x));
}

template<typename T>
static void
print(const T& x) {
  UnionPrint::p(x);
}

__attribute__((unused)) static void
print(char* x) {
  printf(" %s", x ? x : "<NULL>");
}

__attribute__((unused)) static void
print(const char* x) {
  printf(" %s", x ? x : "<NULL>");
}

#endif  // PRINT_HPP