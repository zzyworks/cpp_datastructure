#include "pm_brute.h"
#include "test_string_pm.hpp"

int*
buildNext(const char* P) {
  int m = (int)strlen(P), j = 0;
  int* next = new int[m];
  //next表，首项必为-1
  int t = next[0] = -1;
  while(j < m - 1) {
    if(0 > t || P[t] == P[j]) {
      ++t;
      ++j;
      //则递增赋值：此处可改进...
      next[j] = t;
    } else
      //继续尝试下一值得尝试的位置
      t = next[t];
  }
  /*DSA*/ printString(P);
  printf("\n");
  /*DSA*/ printNext(next, 0, m);
  return next;
}

int
match3(const char* T, const char* P) {
  //构造next表
  int* next = buildNext(P);
  //文本串指针
  int n = (int)strlen(T), i = 0;
  //模式串指针
  int m = (int)strlen(P), j = 0;
  //自左向右逐个比对字符
  while((j < m) && (i < n)) {
    /*DSA*/ showProgress(T, P, i - j, j);
    /*DSA*/ printNext(next, i - j, strlen(P));
    /*DSA*/ getchar();
    printf("\n");
    //若匹配，或P已移出最左侧（两个判断的次序不可交换）
    if(0 > j || T[i] == P[j]) {
      i++;
      j++;
    }               //则转到下一字符
    else            //否则
      j = next[j];  //模式串右移（注意：文本串不用回退）
  }
  delete[] next;  //释放next表
  return i - j;
}