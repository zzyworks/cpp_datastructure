#include "pm_brute.h"

#define printString(s)                           \
  {                                              \
    for(size_t m = strlen(s), k = 0; k < m; k++) \
      printf("%4c", (s)[k]);                     \
  }

/*
 * 显示Next[]表，供演示分析
 */
void printNext(int* N, int offset, int length);

/*
 * Text     :  0   1   2   .   .   .   i   i+1 .   .   .   i+j .   .   n-1
 *             ------------------------|-------------------|------------
 * Pattern  :                          0   1   .   .   .   j   .   .
 *                                     |-------------------|
 *
 * 动态显示匹配进展
 * i为P相对于T的起始位置，j为P的当前字符
 */
void showProgress(const char* T, const char* P, int i, int j);

// #include "test_string_pm.hpp"
// 
// int
// main(int argc, char* argv[]) {
//   if(3 > argc) {
//     fprintf(stderr,
//             "\nUsage: %s <Pattern> <Text>\n\nFor example %s people \"now is "
//             "the time for all good people to come\"\n\n",
//             argv[0], argv[0]);
//     return -1;
//   }
//   for(int i = 0; i < (argc - 1) / 2 * 2; i += 2) {
//     /*DSA*/ printf("####################################################\n");
//     /*DSA*/ printf("Text:     ");
//     printString(argv[i + 2]);
//     printf("\n");
//     /*DSA*/ printf("Pattern:  ");
//     printString(argv[i + 1]);
//     printf("\n");
//     int pos = match3(argv[i + 2], argv[i + 1]);
//     /*DSA*/ if(strlen(argv[i + 2]) < pos + strlen(argv[i + 1]))
//       printf("No matching found\n");
//     /*DSA*/ else
//       printf("Matching found at #%d\n", pos);
//   }
//   return 0;
// }