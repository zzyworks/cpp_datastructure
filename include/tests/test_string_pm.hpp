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