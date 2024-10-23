#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <array>
#include <functional>

template<typename T, std::size_t Size>
void
merge(std::array<T, Size>& arr, int first, int mid, int last,
      std::function<bool(const T&, const T&)> cmp,
      std::array<T, Size>& tmp_arr) {
  int i = first, j = mid + 1, k = 0;
  while(i <= mid && j <= last)
    tmp_arr[k++] = cmp(arr[i], arr[j]) ? arr[i++] : arr[j++];
  while(i <= mid)
    tmp_arr[k++] = arr[i++];
  while(j <= last)
    tmp_arr[k++] = arr[j++];
  for(int m = 0; m != k; ++m)
    arr[first + m] = tmp_arr[m];
}

template<typename T, std::size_t Size>
void
mergeSortAux(std::array<T, Size>& arr, int first, int last,
         std::function<bool(const T&, const T&)> cmp,
         std::array<T, Size>& tmp_arr) {
  if(first >= last)
    return;
  int mid = (last + first) / 2;
  mergeSortAux(arr, first, mid, cmp, tmp_arr);
  mergeSortAux(arr, mid + 1, last, cmp, tmp_arr);
  merge(arr, first, mid, last, cmp, tmp_arr);
}

template<typename T, std::size_t Size>
void
mergeSort(std::array<T, Size>& arr,
          std::function<bool(const T&, const T&)> cmp = std::less_equal<T>()) {
  std::array<T, Size> tmp_arr;
  mergeSortAux(arr, 0, static_cast<int>(Size - 1), cmp, tmp_arr);
}

#endif  // ! MERGE_SORT_HPP