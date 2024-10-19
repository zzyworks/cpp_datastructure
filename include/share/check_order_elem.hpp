#ifndef CHECK_ORDER_ELEM_HPP
#define CHECK_ORDER_ELEM_HPP 1

// 函数对象：判断一个T类对象是否局部有序
template<typename T>
struct CheckOrder {  
  T pred;
  int& u;

  CheckOrder(T& first, int& unsorted) : pred(first), u(unsorted) {}

  void operator()(T& e) {
    if(pred > e)
      u++;
    pred = e;
  }
};

#endif  // CHECK_ORDER_ELEM_HPP