#include "bubble_sort.hpp"
#include "print.hpp"

void
testBubbleSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");
  bubbleSort(arr, 0, arr.size());
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