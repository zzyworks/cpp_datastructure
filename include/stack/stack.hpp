#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

template<class T, typename Container = Vector<T>>
class Stack {
public:
  using size_type = typename Container::size_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;

private:
  Container c_;

public:
  Stack() : c_() {}

  ~Stack() = default;

  reference top() { return c_.back(); }

  const_reference top() const { return c_.back(); }

  bool empty() const { return c_.empty(); }

  size_type size() const { return c_.size(); }

  void push(const T& value) { c_.pushBack(value); }

  void pop() { c_.popBack(); }

  void traverse(void (*fn)(T&)) {
    c_.traverse(fn);
  }

  // 遍历向量
  template<typename Fn>
  void traverse(Fn&& fn) {
    c_.traverse(std::forward<Fn>(fn));
  }
};

#endif  // STACK_HPP