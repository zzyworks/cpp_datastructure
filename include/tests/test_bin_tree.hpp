#include "print.hpp"
#include "utility.h"

#include "bin_tree.hpp"

int testID = 0;  //测试编号

// 随机生成期望高度为h的二叉树
template<typename T>
bool
randomBinTree(BinTree<T>& btA, iterator<T> x, int h) {
  if(0 >= h)
    return false;  //至多h层
  if(0 < dice(h))  //以1/h的概率终止当前分支的生长
    randomBinTree(btA, btA.insertRC(x, dice((T)h * h * h)), h - 1);
  if(0 < dice(h))  //以1/h的概率终止当前分支的生长
    randomBinTree(btA, btA.insertLC(x, dice((T)h * h * h)), h - 1);
  return true;
}

// 在二叉树中随机确定一个节点位置
template<typename T>
iterator<T>
randomPosiInBinTree(iterator<T> root) {
  if(isLeaf(root))
    return root;
  if(!root->l_child)
    return dice(6) ? randomPosiInBinTree(root->r_child) : root;
  if(!root->r_child)
    return dice(6) ? randomPosiInBinTree(root->l_child) : root;
  return dice(2) ? randomPosiInBinTree(root->l_child)
                 : randomPosiInBinTree(root->l_child);
}

template<typename T>
void
testBinTree(int h) {  //测试二叉树
  printf("\n  ==== Test %2d. Generate a binTree of height <= %d \n", testID++,
         h);
  BinTree<T> btA;
  print(btA);
  btA.insertRoot(dice((T)h * h * h));
  print(btA);
  randomBinTree<T>(btA, btA.root(), h);
  print(btA);

  printf("\n  ==== Test %2d. Double and increase all nodes by traversal\n",
         testID++);
  btA.travPrev(Double<T>());
  btA.travPrev(Increase<T>());
  print(btA);
  btA.travIn(Double<T>());
  btA.travIn(Increase<T>());
  print(btA);
  btA.travPost(Double<T>());
  btA.travPost(Increase<T>());
  print(btA);
  btA.travLevel(Double<T>());
  btA.travLevel(Increase<T>());
  print(btA);
  Hailstone<T> hs;
  btA.travIn(hs);
  print(btA);

  printf("\n  ==== Test %2d. Create a shadow by copying\n", testID++);
  BinTree<T> btB(btA);  //等效：BinTree<T> btB = btA;
  print(btB);

  printf("\n  ==== Test %2d. Create a HART by attaching\n", testID++);
  iterator<T> p;
  p = btB.root();
  while(p->l_child)
    p = p->l_child;
  btB.attachLC(p, btA);
  p = btB.root();
  while(p->l_child)
    p = p->l_child;
  btB.attachLC(p, btA);
  iterator<T> q;
  q = btB.root();
  while(q->r_child)
    q = q->r_child;
  btB.attachRC(q, btA);
  q = btB.root();
  while(q->r_child)
    q = q->r_child;
  btB.attachRC(q, btA);
  print(btB);

  printf("\n  ==== Test %2d. Remove subtrees\n", testID++);
  while(!btB.empty()) {
    iterator<T> p = randomPosiInBinTree(btB.root());  //随机选择一个节点
    if(dice(2)) {
      printf("removing ");
      print(p->data);
      printf(" ...\n");
      printf("%d node(s) removed\n", btB.remove(p));
      print(btB);
    } else {
      printf("releasing ");
      print(p->data);
      printf(" ...\n");
      auto S = btB.secede(p);
      print(S);
      printf("%d node(s) released\n", S->size());
      S->remove(S->root());
      S = nullptr;
      print(btB);
    }
  }
}

// #include "test_bin_tree.hpp"
// 
// int
// main(int argc, char* argv[]) {  //测试二叉树
//   if(2 > argc) {
//     printf("Usage: %s <size of test>\a\a\n", argv[0]);
//     return 1;
//   }
//   srand((unsigned int)time(NULL));
//   //srand( 31415926 ); //固定种子（假种子，调试用）
//   testBinTree<int>(atoi(argv[1]));  //元素类型可以在这里任意选择
//   return 0;
// }