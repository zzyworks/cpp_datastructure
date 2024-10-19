#ifndef RAND_HPP
#define RAND_HPP

#include <stdlib.h>
#include <time.h>  //通常用当前时刻设置随机种子

/******************************************************************************************
 * 在[0, range)内随机生成一个数
 ******************************************************************************************/

// 取[0, range)中的随机整数
__attribute__((unused)) static int
dice(int range) {
  return rand() % range;
}

// 取[lo, hi)中的随机整数
__attribute__((unused)) static int
dice(int lo, int hi) {
  return lo + rand() % (hi - lo);
}

__attribute__((unused)) static float
dice(float range) {
  return rand() % (1000 * (int)range) / (float)1000.;
}

__attribute__((unused)) static double
dice(double range) {
  return rand() % (1000 * (int)range) / (double)1000.;
}

__attribute__((unused)) static char
dice(char range) {
  return (char)(32 + rand() % 96);
}

#endif  // RAND_HPP