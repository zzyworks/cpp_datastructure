#include "bubble_sort.hpp"
#include "heap_sort.hpp"
#include "insert_sort.hpp"
#include "merge_sort.hpp"
#include "print.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"

void
testBubbleSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");

  bubbleSort(arr);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");

  bubbleSort<int>(arr, std::greater<int>());
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");
}

void
testSelectionSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");

  selectionSort(arr);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");

  selectionSort<int>(arr, std::greater<int>());
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");
}

void
testInsertSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");

  insertSort(arr);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");

  insertSort<int>(arr, std::greater<int>());
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");
}

void
testShellSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");

  shellSort(arr);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");

  shellSort<int>(arr, std::greater<int>());
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");
}

void
testMergeSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");

  mergeSort(arr);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");

  mergeSort<int>(arr, std::greater_equal<int>());
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");
}

void
testQuickSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");

  quickSort(arr);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");

  quickSort<int>(arr, std::greater_equal<int>());
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");
}

void
testHeapSort() {
  std::array<int, 20> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10,
                             1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  MSG("", "排序前...")
  for(int i : arr)
    print(i);
  print("\n");

  heapSort(arr);
  MSG("", "排序后...")
  for(int i : arr)
    print(i);
  print("\n");

  heapSort<int>(arr, std::greater_equal<int>());
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