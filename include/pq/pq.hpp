#ifndef PQ_HPP
#define PQ_HPP

//优先级队列PQ接口
template<typename T>
struct PQ {
  virtual ~PQ() = default;
  virtual void insert(const T&) = 0;
  virtual T delMax() = 0;
  virtual T& getMax() = 0;
};

#endif  // PQ_HPP