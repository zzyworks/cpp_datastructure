// #include <stdio.h>
// #include "bitmap.h"
// #include "eratosthenes.h"
// #include "prime_nlt.h"
// #include "rand.hpp"
// 
// //用于记录指定区间内素数分布的比特图文件
// #define PRIME_FILE "prime-bitmap.txt"
// 
// int
// main(int argc, char* argv[]) {
//   srand((unsigned int)time(NULL));  //设置随机种子
//   if(2 > argc) {
//     printf("Usage: %s <maxInt>\n", argv[0]);
//     return -1;
//   }
//   int n = atoi(argv[1]);  //简化起见，不考虑非正的情况
//   eratosthenes(PRIME_FILE, n);
//   for(int i = 0; i < 13;
//       i++) {  //做13次随机测试（限于MAX_RAND，覆盖范围不超过0x7FFF）
//     int low = dice(n);
//     printf("The smallest prime number no less than %8d (%05X) is %8d\n", low,
//            low, primeNLT(PRIME_FILE, low, n));
//   }
//   for(int i = 0; i < 13; i++) {  //做13次等间距测试
//     printf("The smallest prime number no less than %8d (%05X) is %8d\n",
//            n * i / 13, n * i / 13, primeNLT(PRIME_FILE, n * i / 13, n));
//   }
//   return 0;
// }