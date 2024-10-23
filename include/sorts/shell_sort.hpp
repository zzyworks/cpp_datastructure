#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <array>
#include <functional>

template<typename T, std::size_t Size>
void
shellSort(std::array<T, Size>& arr,
          std::function<bool(const T&, const T&)> cmp = std::less<T>()) {
  for(int gap = static_cast<int>(Size); gap >= 1; gap /= 2) {
    for(int i = gap; i != static_cast<int>(Size); i += gap) {
      T tmp = arr[i];
      int prev = i - gap;
      for(; prev >= 0 && cmp(tmp, arr[prev]); prev -= gap)
        arr[prev + gap] = arr[prev];
      arr[prev + gap] = tmp;
    }
  }
}

#endif  // ! SHELL_SORT_HPP