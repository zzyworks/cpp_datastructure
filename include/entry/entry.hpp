#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <utility>

template<typename K, typename V>
struct Entry {
  using container_type = std::pair<K, V>;
  using key_type = typename container_type::first_type;
  using value_type = typename container_type::second_type;

  container_type base;

  Entry(const key_type& key, const value_type& value)
      : base(std::make_pair(key, value)) {}

  Entry(const Entry& other) : base(other) {}

  Entry(Entry&& other) : base(std::move(other)) {}

  ~Entry() = default;

  Entry& operator=(const Entry& other) {
    if(this != &other) {
      base = other;
    }
    return *this;
  }

  Entry& operator=(Entry&& other) {
    if(this != &other) {
      base = std::move(other);
    }
    return *this;
  }
};

template<typename K, typename V>
bool
operator<(const Entry<K, V>& x, const Entry<K, V>& y) {
  return x.base < y.base;
}

template<typename K, typename V>
bool
operator>(const Entry<K, V>& x, const Entry<K, V>& y) {
  return y.base < x.base;
}

template<typename K, typename V>
bool
operator==(const Entry<K, V>& x, const Entry<K, V>& y) {
  return x.base == y.base;
}

template<typename K, typename V>
bool
operator!=(const Entry<K, V>& x, const Entry<K, V>& y) {
  return !(x.base == y.base);
}

template<typename K, typename V>
bool
operator<=(const Entry<K, V>& x, const Entry<K, V>& y) {
  return !(y.base < x.base);
}

template<typename K, typename V>
bool
operator>=(const Entry<K, V>& x, const Entry<K, V>& y) {
  return !(x.base < y.base);
}

#endif  // ENTRY_HPP