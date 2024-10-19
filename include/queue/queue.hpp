#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

template<class T, class Container = List<T>>
class Queue {
public:
  using container_type = Container;
  using size_type = typename Container::size_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;

private:
  Container c_;

public:
  Queue() : c_() {}

  ~Queue() = default;

  reference front() {
    return c_.front();
  }

  const_reference front() const {
    return c_.front();
  }

  reference back() {
    return c_.back();
  }

  const_reference back() const {
    return c_.back();
  }

  bool empty() const {
    return c_.empty();
  }

  size_type size() const {
    return c_.size();
  }

  void push(const T& value) {
    c_.pushBack(value);
  }

  void pop() {
    c_.popFront();
  }

  void traverse(void (*fn)(T&)) {
    c_.traverse(fn);
  }

  // 遍历向量
  template<typename Fn>
  void traverse(Fn&& fn) {
    c_.traverse(std::forward<Fn>(fn));
  }
};

#endif  // QUEUE_HPP