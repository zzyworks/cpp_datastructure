#ifndef INCREASE_LIST_HPP
#define INCREASE_LIST_HPP

#include "list.hpp"

#include "increase_elem.hpp"

//统一递增列表中的各元素
template<typename T>
void
increase(List<T>& L) {
  //以Increase<T>()为基本操作进行遍历
  L.traverse(Increase<T>());
}

#endif  // INCREASE_LIST_HPP