#include "pm_brute.h"

int
match2(const char* T, const char* P) {
  //T长度、与P首字符的对齐位置
  int n = strlen(T), i;
  //P长度、当前接受比对字符的位置
  int m = strlen(P), j;
  //T从第i个字符起，与
  for(i = 0; i + m <= n; i++) {
    //P中对应的字符逐个比对
    for(j = 0; j < m; j++) {
      /*DSA begin*/
      showProgress(T, P, i, j);
      //若失配，P右移一个字符，再做一轮比对
      if(T[i + j] != P[j])
        break;
      /*DSA end*/
    }
    //找到匹配子串
    if(j >= m)
      break;
  }
  return i;  //如何通过返回值，判断匹配结果？
}