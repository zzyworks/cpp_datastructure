#ifndef INCREASE_VECTOR_HPP
#define INCREASE_VECTOR_HPP

#include "increase_elem.hpp"
#include "vector.hpp"


//统一递增向量中的各元素
template<typename T>
void
increase(Vector<T>& V) {
  //以Increase<T>()为基本操作进行遍历
  V.traverse(Increase<T>());
}

#endif  // INCREASE_VECTOR_HPP