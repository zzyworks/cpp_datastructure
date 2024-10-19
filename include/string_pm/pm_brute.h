#ifndef PM_BRUTE_H
#define PM_BRUTE_H

#include <cstdio> /*DSA*/

#include <cstring>

/*DSA*/
void showProgress(const char*, const char*, int, int);

/*
 * Text     :  0   1   2   .   .   .   i-j .   .   .   .   i   .   .   n-1
 *             ------------------------|-------------------|------------
 * Pattern  :                          0   .   .   .   .   j   .   .
 *                                     |-------------------|
 */

//串匹配算法（Brute-force-1）
int match1(const char* T, const char* P);

/*
 * Text     :  0   1   2   .   .   .   i   i+1 .   .   .   i+j .   .   n-1
 *             ------------------------|-------------------|------------
 * Pattern  :                          0   1   .   .   .   j   .   .
 *                                     |-------------------|
 */

//串匹配算法（Brute-force-2）
int match2(const char* T, const char* P);

//构造模式串P的next表
int* buildNext(const char* P);
//KMP算法
int match3(const char* T, const char* P);

#endif  // PM_BRUTE_H