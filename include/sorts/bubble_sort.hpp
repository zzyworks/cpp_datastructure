#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <array>

template<typename T, std::size_t Size>
bool
bubble(std::array<T, Size>& arr, std::size_t first, std::size_t last) {
  bool sorted = true;
  while(++first < last) {
    if(arr[first - 1] > arr[first]) {
      sorted = false;
      using std::swap;
      swap(arr[first - 1], arr[first]);
    }
  }
  return sorted;
}

// [first, last)
template<typename T, std::size_t Size>
void
bubbleSort(std::array<T, Size>& arr, std::size_t first, std::size_t last) {
  while(!bubble(arr, first, last--))
    ;
}

#endif  // ! BUBBLE_SORT_HPP