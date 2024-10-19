#include "print.hpp"
#include "utility.h"

#include "queue.hpp"

int testID = 0;  //测试编号

/******************************************************************************************
* 测试栈
******************************************************************************************/
template<typename T>  //元素类型
void
testQueue(int n) {
  Queue<T> Q;

  printf("\n  ==== Test %2d. Growing queue\n", testID++);
  while(Q.size() < n) {
    (Q.empty() || (30 < dice(100))) ? Q.push(dice((T)2 * n)) :  //70%入队
      Q.pop();                                                 //30%出队
    print(Q);
  }

  printf("\n  ==== Test %2d. Shrinking queue\n", testID++);
  while(!Q.empty()) {
    (70 < dice(100)) ? Q.push(dice((T)2 * n)) :  //30%入队
      Q.pop();                                  //70%出队
    print(Q);
  }
}

// #include "test_queue.hpp"
// 
// /*
//  * 测试队列
//  */
// int
// main(int argc, char* argv[]) {
//   if(2 > argc) {
//     printf("Usage: %s <size of test>\a\a\n", argv[0]);
//     return 1;
//   }
//   srand((unsigned int)time(NULL));
//   testQueue<int>(atoi(argv[1]));  //元素类型可以在这里任意选择
//   return 0;
// }