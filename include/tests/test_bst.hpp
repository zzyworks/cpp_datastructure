#include "print.hpp"
#include "utility.h"

#include "bst.hpp"

/*
 * Test a BST
 */
template<typename T>
void
testBST(int n) {
  if(n < 1)
    return;
  BST<T> bst;
  //
  while(bst.size() < n)
    bst.insert(dice((T)n * 3));
  print(bst);  //随机创建
  bst.stretchToLPath();
  print(bst);  //伸直成撇
  while(!bst.empty())
    bst.remove(bst.root()->data);  //清空
                                   //
  while(bst.size() < n)
    bst.insert(dice((T)n * 3));
  print(bst);  //随机创建
  bst.stretchToRPath();
  print(bst);  //伸直成捺
  while(!bst.empty())
    bst.remove(bst.root()->data);  //清空
                                   //
  while(bst.size() < n)
    bst.insert(dice((T)n * 3));
  print(bst);                         //随机创建
  stretchByZig(bst.root()->l_child);  //左子树伸直成捺
  stretchByZag(bst.root()->r_child);  //右子树伸直成撇
  print(bst);
  while(!bst.empty())
    bst.remove(bst.root()->data);  //清空
                                   //
  while(bst.size() < n)
    bst.insert(dice((T)n * 3));
  print(bst);                         //随机创建
  stretchByZag(bst.root()->l_child);  //左子树伸直成撇
  stretchByZig(bst.root()->l_child);  //右子树伸直成捺
  print(bst);
  while(!bst.empty())
    bst.remove(bst.root()->data);  //清空
                                   //
  while(bst.size() < n) {          //随机插入、查询、删除
    T e = dice((T)n * 3);          //[0, 3n)范围内的e
    switch(dice(3)) {
      case 0: {  //查找，成功率 <= 33.3%
        printf("Searching for ");
        print(e);
        printf(" ... ");
        iterator<T>& p = bst.search(e);
        p              ? printf("Found with"), print(p->data),
          printf("\n") : printf("not found\n");
        break;
      }
      case 1: {  //删除，成功率 <= 33.3%
        printf("Removing ");
        print(e);
        printf(" ... ");
        if(bst.remove(e)) {
          printf("Done\n");
          print(bst);
        } else
          printf("not exists\n");
        break;
      }
      default: {  //插入，成功率 == 100%
        printf("Inserting ");
        print(e);
        printf(" ... ");
        printf("Done with"), print(bst.insert(e)->data), printf("\n"),
          print(bst);
        break;
      }
    }
  }
  while(bst.size() > 0) {  //清空
    T e = dice((T)n * 3);  //[0, 3n)范围内的e
    printf("Removing ");
    print(e);
    printf(" ... ");
    if(bst.remove(e)) {
      printf("Done\n");
      print(bst);
    } else
      printf("not exists\n");
  }
}

// #include "test_bst.hpp"
// 
// int
// main(int argc, char* argv[]) {
//   if(2 > argc) {
//     printf("Usage: %s <size of test>\a\a\n", argv[0]);
//     return 1;
//   }
//   srand((unsigned int)time(NULL));  //随机种子
//   //srand( 31415926 ); //固定种子（假种子，调试用）
//   testBST<int>(atoi(argv[1]));  //元素类型可以在这里任意选择
//   return 0;
// }