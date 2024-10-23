#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <array>
#include <functional>

template<typename T, std::size_t Size>
void
bubbleSort(std::array<T, Size>& arr,
           std::function<bool(const T&, const T&)> cmp = std::less<T>()) {
  for(int i = 0; i != static_cast<int>(Size) - 1; ++i) {
    bool flag = true;
    for(int j = 0; j != static_cast<int>(Size) - 1 - i; ++j) {
      if(cmp(arr[j + 1], arr[j])) {
        using std::swap;
        swap(arr[j + 1], arr[j]);
        flag = false;
      }
    }
    if(flag)
      break;
  }
}

#endif  // ! BUBBLE_SORT_HPP