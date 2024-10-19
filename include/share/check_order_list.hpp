#ifndef CHECK_ORDER_LIST_HPP
#define CHECK_ORDER_LIST_HPP 1

#include <cstdio>

#include "list.hpp"
#include "check_order_elem.hpp"

// 判断列表是否整体有序
template<typename T>
void
checkOrder(List<T>& L) {
  int unsorted = 0;                                      //逆序计数器
  L.traverse(CheckOrder<T>(L.front(), unsorted));  //进行遍历
  if(0 < unsorted)
    printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
  else
    printf("Sorted\n");
  printf("DISORDERED = %d\n", L.disordered());
}

#endif  // CHECK_ORDER_LIST_HPP