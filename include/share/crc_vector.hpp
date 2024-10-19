#ifndef CRC_VECTOR_HPP
#define CRC_VECTOR_HPP

#include <cstdio>
#include "crc_elem.hpp"
#include "vector.hpp"

//统计向量的特征（所有元素之和）
template<typename T>
void
crc(Vector<T>& V) {
  T crc = 0;
  V.traverse(Crc<T>(crc));  //以crc为基本操作进行遍历
  printf("CRC =");
  print(crc);
  printf("\n");  //输出统计得到的特征
}

#endif  // CRC_VECTOR_HPP