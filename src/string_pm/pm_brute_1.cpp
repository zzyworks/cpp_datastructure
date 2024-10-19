#include "pm_brute.h"

int
match1(const char* T, const char* P) {
  //文本串长度、当前接受比对字符的位置
  int n = strlen(T), i = 0;
  //模式串长度、当前接受比对字符的位置
  int m = strlen(P), j = 0;
  //自左向右逐个比对字符
  while((j < m) && (i < n)) {
    /*DSA*/
    showProgress(T, P, i - j, j);
    if(T[i] == P[j]) {
      i++;
      j++;
    } else {
      //文本串回退、模式串复位
      i -= j - 1;
      j = 0;
    }
  }
  return i - j;  //如何通过返回值，判断匹配结果？
}