#ifndef CRC_LIST_HPP
#define CRC_LIST_HPP

#include <cstdio>
#include "crc_elem.hpp"
#include "list.hpp"


//统计列表的特征（所有元素总和）
template<typename T>
void
crc(List<T>& L) {
  T crc = 0;
  L.traverse(Crc<T>(crc));  //以crc为基本操作进行遍历
  printf("CRC =");
  print(crc);
  printf("\n");  //输出统计得到的特征
}

#endif  // CRC_LIST_HPP