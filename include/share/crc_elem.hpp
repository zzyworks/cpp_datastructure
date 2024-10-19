#ifndef CRC_ELEM_HPP
#define CRC_ELEM_HPP

//函数对象：累计T类对象的特征（比如总和），以便校验对象集合
template<typename T>
struct Crc {
  T& c;

  Crc(T& crc) : c(crc) {}

  //假设T可直接相加
  void operator()(T& e) { c += e; }
};

#endif  // CRC_ELEM_HPP