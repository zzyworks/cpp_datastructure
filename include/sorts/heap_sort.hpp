#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <array>
#include <functional>

template<typename T, std::size_t Size>
void
adjustHeap(std::array<T, Size>& arr, int length, int index,
           std::function<bool(const T&, const T&)> cmp) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int max_index = index;
  if(left < length && cmp(arr[max_index], arr[left]))
    max_index = left;
  if(right < length && cmp(arr[max_index], arr[right]))
    max_index = right;
  if(max_index != index) {
    using std::swap;
    swap(arr[max_index], arr[index]);
    adjustHeap(arr, length, max_index, cmp);
  }
}

template<typename T, std::size_t Size>
void
heapSort(std::array<T, Size>& arr,
         std::function<bool(const T&, const T&)> cmp = std::less<T>()) {
  for(int i = static_cast<int>(Size) / 2; i >= 0; --i)
    adjustHeap(arr, static_cast<int>(Size), i, cmp);
  for(int i = static_cast<int>(Size) - 1; i >= 1; --i) {
    using std::swap;
    swap(arr[0], arr[i]);
    adjustHeap(arr, i, 0, cmp);
  }
}

#endif  // !HEAP_SORT_HPP