#ifndef DOUBLE_ELEM_HPP
#define DOUBLE_ELEM_HPP

// 函数对象：倍增一个T类对象
template<typename T>
struct Double {
  //假设T可直接倍增
  void operator()(T& e) { e *= 2; }
};

#endif  // DOUBLE_ELEM_HPP