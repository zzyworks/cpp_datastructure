#include "heap_sort.hpp"
#include "print.hpp"

int arr[]{0, 1, 3, 5, 7, 9, 0, 1, 3, 5, 7, 9};

void testHeapSort() {
  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");
  heapSort(arr, 0, 12);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");
}

// #include "test_sorts.hpp"
// 
// int
// main(int argc, char* argv[]) {
//   testHeapSort();
// }