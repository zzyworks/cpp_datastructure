#ifndef DECREASE_LIST_HPP
#define DECREASE_LIST_HPP

#include "decrease_elem.hpp"
#include "list.hpp"

//统一递减列表中的各元素
template<typename T>
void
decrease(List<T>& L) {
  //以Decrease<T>()为基本操作进行遍历
  L.traverse(Decrease<T>());
}

#endif  // DECREASE_LIST_HPP