#ifndef DICTIONARY_H
#define DICTIONARY_H

template<class K, class V>
struct Dictionary {
  using key_type = K;
  using value_type = V;
  using size_type = int;
  using reference_k = K&;
  using const_reference_k = const K&;
  using reference_v = V&;
  using const_reference_v = const V&;
  using pointer_k = K*;
  using const_pointer_k = const K*;
  using pointer_v = V*;
  using const_pointer_v = const V*;

  virtual size_type size() const = 0;
  virtual bool put(const key_type& key, const value_type& value) = 0;
  virtual pointer_v get(const key_type& key) = 0;
  virtual bool erase(const key_type& key) = 0;
};

#endif // DICTIONARY_H