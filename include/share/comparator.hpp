#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include <functional>

// less than
template<typename T>
static bool
lt(T&& a, T&& b) {
  return std::less<T>(a, b);
}

// equal
template<typename T>
static bool
eq(T&& a, T&& b) {
  return std::equal_to<T>(a, b);
}

#endif  // COMPARATOR_HPP