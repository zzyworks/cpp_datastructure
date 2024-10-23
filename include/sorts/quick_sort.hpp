#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <array>
#include <functional>

template<typename T, std::size_t Size>
void
quickSortAux(std::array<T, Size>& arr, int first, int last,
             std::function<bool(const T&, const T&)> cmp) {
  if(first >= last)
    return;
  int i = first, j = last, pivot = arr[i];
  while(i < j) {
    while(i < j && cmp(pivot, arr[j]))
      --j;
    if(i < j)
      arr[i] = arr[j];
    while(i < j && cmp(arr[i], pivot))
      ++i;
    if(i < j)
      arr[j] = arr[i];
  }
  arr[i] = pivot;
  quickSortAux(arr, first, i - 1, cmp);
  quickSortAux(arr, i + 1, last, cmp);
}

template<typename T, std::size_t Size>
void
quickSort(std::array<T, Size>& arr,
          std::function<bool(const T&, const T&)> cmp = std::less_equal<T>()) {
  quickSortAux(arr, 0, static_cast<int>(Size) - 1, cmp);
}
#endif  // ! QUICK_SORT_HPP