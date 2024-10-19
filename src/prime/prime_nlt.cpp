#include "bitmap.h"
#include "prime_nlt.h"

//根据file文件中的记录，在[first, last)内取最小的素数
int
primeNLT(const char* file, int first, int last) {
  //file已经按位图格式，记录了last以内的所有素数，因此只要
  Bitmap B(file, last);
  while(first < last)  //从first开始，逐位地
    if(B.test(first))
      first++;  //测试，即可
    else
      return first;  //返回首个发现的素数
  return first;  //若没有这样的素数，返回n（实用中不能如此简化处理）
}