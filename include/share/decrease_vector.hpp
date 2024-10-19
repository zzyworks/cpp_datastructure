#ifndef DECREASE_VECTOR_HPP
#define DECREASE_VECTOR_HPP

#include "decrease_elem.hpp"
#include "vector.hpp"

//统一递减向量中的各元素
template<typename T>
void
decrease(Vector<T>& V) {
  //以Decrease<T>()为基本操作进行遍历
  V.traverse(Decrease<T>());
}

#endif  // DECREASE_VECTOR_HPP