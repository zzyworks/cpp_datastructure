#include <cstring>
#include <iostream>

int*
buildNext(const char* P) {
  int len = (int)strlen(P), j = 0;
  int* next = new int[len];
  //next表，首项必为-1
  int k = next[0] = -1;
  while(j < len - 1) {
    if(k == -1 || P[j] == P[k]) {
      ++k;
      ++j;
      next[j] = k;
    } else
      //继续尝试下一值得尝试的位置
      k = next[k];
  }
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

int main() {
  const char* T = "aabaabaaf";
  const char* P = "aabaaf";
  std::cout << match3(T, P) << "\n";
  return 0;
}