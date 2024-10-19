#ifndef PERMUTE_HPP
#define PERMUTE_HPP

#include "vector.hpp"

//随机置乱向量，使各元素等概率出现于各位置
template<typename T>
void
permute(Vector<T>& V) {
  for(int i = V.size(); i > 0; i--)  //自后向前
    std::swap(V[i - 1], V[rand() % i]);  //V[i - 1]与V[0, i)中某一随机元素交换
}

#endif  // PERMUTE_HPP