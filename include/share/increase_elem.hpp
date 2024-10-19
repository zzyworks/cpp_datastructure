#ifndef INCREASE_ELEM_HPP
#define INCREASE_ELEM_HPP

// 函数对象：递增一个T类对象
template<typename T>
struct Increase {
  //假设T可直接递增或已重载++
  virtual void operator()(T& e) { ++e; }
};

#endif  // INCREASE_ELEM_HPP