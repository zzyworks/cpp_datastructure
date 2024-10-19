/******************************************************************************************
 * 支持Huffman编码的数据结构
 ******************************************************************************************
 * 采用统一的接口，为Huffman_PQ_ComplHeap和Huffman_PQ_LeftHeap共用
 * 编译之前，可通过在对应的工程中设置DSA_PQ_ComplHeap或DSA_PQ_LeftHeap选择
 ******************************************************************************************/

#ifndef HUFFMAN_PQ_H
#define HUFFMAN_PQ_H

/*DSA*/
#include "print.hpp"

//Huffman树
#include "huff_code.h"   //引入HuffCode二进制编码
#include "huff_table.h"  //引入Huffman编码表
#include "huff_tree.h"   //引入Huffman树

// Huffman森林
#if defined(DSA_PQ_LIST)
#include "../Huffman/Huffman_Forest_PQ_List.h"
#elif defined(DSA_PQ_COMPLHEAP)
#include "../Huffman/Huffman_Forest_PQ_ComplHeap.h"
#elif defined(DSA_PQ_LEFTHEAP)
#include "../Huffman/Huffman_Forest_PQ_LeftHeap.h"
#else  //朴素方案：直接用List实现的Huffman森林
#include "huffman_forest_list.h"
#endif


// #include "test_huffman.hpp"
// 
// /*
//  * 无论编码森林由列表、完全堆还是左式堆实现，本测试过程都可适用
//  * 编码森林的实现方式采用优先级队列时，编译前对应的工程只需设置相应标志：
//  *    DSA_PQ_List、DSA_PQ_ComplHeap或DSA_PQ_LeftHeap
//  */
// int
// main(int argc, char* argv[]) {  //Huffman编码算法统一测试
//   /*DSA*/ if(3 > argc) {
//     printf("Usage: %s <sample-text-file> <message#1> [message#2] ...\a\n",
//            argv[0]);
//     return -1;
//   }
//   //根据样本文件，统计各字符的出现频率
//   auto freq = statistics(argv[1]);
//   //创建Huffman森林
//   auto forest = initForest(freq);
//   auto tree = generateTree(forest);
//   //输出编码树
//   /*DSA*/ print(tree);
//   //将Huffman编码树转换为编码表
//   auto table = generateTable(tree);
//   //输出编码表
//   for(int i = 0; i < N_CHAR; i++) {
//     auto p = table.get(i + 0x20);
//     if(p)
//       printf(" %c: %s\n", i + 0x20, *p);
//   }
//   for(int i = 2; i < argc; i++) {  //对于命令行传入的每一明文串
//     /*DSA*/ printf("\nEncoding: %s\n", argv[i]);   //以下测试编码
//     auto codeString = std::make_unique<Bitmap>();  //二进制编码串
//     int n = encode(table, codeString, argv[i]);  //将根据编码表生成（长度为n）
//     /*DSA*/ printf("%s\n", codeString->bitsToString(n).c_str());  //输出该编码串
//     /*DSA*/ printf("Decoding: ");  //以下测试解码
//     //利用Huffman编码树，对长度为n的二进制编码串解码
//     decode(tree, codeString, n);
//   }
//   return 0;  //释放编码表、编码树
// }

#endif  // HUFFMAN_PQ_H