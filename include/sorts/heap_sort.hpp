#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "pq_compl_heap.hpp"

template<typename T>
void heapSort(T* arr, size_type first, size_type last) {
  T* A = arr + first;
  size_type n = last - first;
  heapify(A, n);
  while(0 < --n) {
    using std::swap;
    swap(A[0], A[n]);
    percolateDown(A, n, 0);
  }
}

#endif // HEAP_SORT_HPP