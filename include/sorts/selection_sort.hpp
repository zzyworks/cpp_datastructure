#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <array>
#include <functional>

template<typename T, std::size_t Size>
void
selectionSort(std::array<T, Size>& arr,
              std::function<bool(const T&, const T&)> cmp = std::less<T>()) {
  for(int i = 0; i != static_cast<int>(Size); ++i) {
    int min_index = i;
    for(int j = i + 1; j != static_cast<int>(Size); ++j) {
      if(cmp(arr[j], arr[min_index]))
        min_index = j;
    }
    if(i != min_index) {
      using std::swap;
      swap(arr[i], arr[min_index]);
    }
  }
}

#endif  // ! SELECTION_SORT_HPP