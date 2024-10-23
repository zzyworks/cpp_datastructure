#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP

#include <array>
#include <functional>

template<typename T, std::size_t Size>
void
insertSort(std::array<T, Size>& arr,
           std::function<bool(const T&, const T&)> cmp = std::less<T>()) {
  for(int i = 1; i != static_cast<int>(Size); ++i) {
    int j = i - 1;
    T tmp = arr[i];
    for(; j >= 0 && cmp(tmp, arr[j]); --j)
      arr[j + 1] = arr[j];
    arr[j + 1] = tmp;
  }
}

#endif  // !INSERT_SORT_HPP