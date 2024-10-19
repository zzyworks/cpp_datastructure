#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include <memory>
#include <type_traits>

template<typename T>
struct is_smart_pointer_helper : public std::false_type {};

template<typename T>
struct is_smart_pointer_helper<std::unique_ptr<T>> : public std::true_type {};

template<typename T>
struct is_smart_pointer
    : public is_smart_pointer_helper<typename std::remove_cv<T>::type> {};

#endif  // TYPE_TRAITS_HPP