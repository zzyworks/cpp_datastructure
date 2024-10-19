#ifndef HAILSTONE_ELEM_HPP
#define HAILSTONE_ELEM_HPP

// 函数对象：按照Hailstone规则转化一个T类对象
template<typename T>
struct Hailstone {
  //假设T可直接做算术运算
   void operator()(T& e) {
      int step = 0;    //转换所需步数
      while(1 != e) {  //按奇、偶逐步转换，直至为1
         (e % 2) ? e = 3 * e + 1 : e /= 2;
         step++;
      }
      e = step;  //返回转换所经步数
   }
};

#endif  // HAILSTONE_ELEM_HPP