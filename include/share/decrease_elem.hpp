#ifndef DECREASE_ELEM_HPP
#define DECREASE_ELEM_HPP

//函数对象：递减一个T类对象
template<typename T>
struct Decrease {
  //假设T可直接递减或已重载--
  void operator()(T& e) { --e; }
};

#endif  // DECREASE_ELEM_HPP