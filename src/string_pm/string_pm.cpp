#include "test_string_pm.hpp"

void
printNext(int* N, int offset, int length) {
  for(int i = 0; i < length; i++)
    printf("%4d", i);
  printf("\n");
  for(int i = 0; i < offset; i++)
    printf("    ");
  for(int i = 0; i < length; i++)
    printf("%4d", N[i]);
  printf("\n\n");
}

void
printBC(int* bc) {
  printf("\n-- bc[] Table ---------------\n");
  for(size_t j = 0; j < 256; j++)
    if(0 <= bc[j])
      printf("%4c", (char)j);
  printf("\n");
  for(size_t j = 0; j < 256; j++)
    if(0 <= bc[j])
      printf("%4d", bc[j]);
  printf("\n\n");
}

void
printGS(char* P, int* GS) {
  printf("-- gs[] Table ---------------\n");
  for(size_t m = strlen(P), j = 0; j < m; j++)
    printf("%4d", j);
  printf("\n");
  printString(P);
  printf("\n");
  for(size_t m = strlen(P), j = 0; j < m; j++)
    printf("%4d", GS[j]);
  printf("\n\n");
}

void
showProgress(const char* T, const char* P, int i, int j) {
  /*DSA*/ static int step = 0;  //操作计数器
  /*DSA*/ printf("\n-- Step %2d: --\n", ++step);
  /*DSA*/ for(size_t n = strlen(T), t = 0; t < n; t++)
    printf("%4d", t);
  printf("\n");
  /*DSA*/ printString(T);
  printf("\n");
  /*DSA*/ if(0 <= i + j)
  /*DSA*/ {
    for(int t = 0; t < i + j; t++)
      printf("%4c", ' ');
    printf("%4c", '|');
  }
  /*DSA*/ printf("\n");
  /*DSA*/ for(int t = 0; t < i; t++)
    printf("%4c", ' ');
  /*DSA*/ printString(P);
  printf("\n");
}