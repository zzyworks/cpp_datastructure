#ifndef PQ_COMPL_HEAP_HPP
#define PQ_COMPL_HEAP_HPP

#include <vector>
#include "pq.hpp"

// clang-format off

#define  Parent(i)         ( ( ( i ) - 1 ) >> 1 ) //PQ[i]的父节点（floor((i-1)/2)，i无论正负）
#define  LChild(i)         ( 1 + ( ( i ) << 1 ) ) //PQ[i]的左孩子
#define  RChild(i)         ( ( 1 + ( i ) ) << 1 ) //PQ[i]的右孩子
#define  InHeap(n, i)      ( ( ( -1 ) != ( i ) ) && ( ( i ) < ( n ) ) ) //判断PQ[i]是否合法
#define  LChildValid(n, i) InHeap( n, LChild( i ) ) //判断PQ[i]是否有一个（左）孩子
#define  RChildValid(n, i) InHeap( n, RChild( i ) ) //判断PQ[i]是否有两个孩子
#define  Bigger(PQ, i, j)  ( ( PQ[i] < PQ[j] ) ? j : i ) //取大者（等时前者优先）
#define  ProperParent(PQ, n, i) /*父子（至多）三者中的大者*/ \
            ( RChildValid(n, i) ? Bigger( PQ, Bigger( PQ, i, LChild(i) ), RChild(i) ) : \
            ( LChildValid(n, i) ? Bigger( PQ, i, LChild(i) ) : i \
            ) \
            ) //相等时父节点优先，如此可避免不必要的交换

// clang-format on

using size_type = int;

//对向量前n个词条中的第pos个实施下滤，pos < n
template<typename T>
size_type
percolateDown(T& heap, size_type n, size_type pos) {
  size_type x;  // i及其（至多两个）孩子中，堪为父者
  while(pos != (x = ProperParent(heap, n, pos))) {
    using std::swap;
    swap(heap[pos], heap[x]);
    pos = x;  //二者换位，并继续考查下降后的pos
  }
  return pos;
}

//对词条heap_[pos]做上滤，0 <= pos < size()
template<typename T>
size_type
percolateUp(T& heap, size_type pos) {
  while(0 < pos) {
    size_type parent = Parent(pos);  //考查[pos]之父亲[parent]
    if(!(heap[parent] < heap[pos]))
      break;  //一旦父子顺序，上滤旋即完成；否则
    using std::swap;
    swap(heap[pos], heap[parent]);
    pos = parent;  //父子换位，并继续考查上一层
  }
  return pos;  //返回上滤最终抵达的位置
}

// Floyd建堆算法
template<typename T>
void
heapify(T& heap, size_type n) {
  for(size_type i = n / 2 - 1; i >= 0; --i)
    percolateDown(heap, n, i);  //经下滤合并子堆
}

template<typename T>
class PQComplHeap : public PQ<T> {  //完全二叉堆
  /*DSA*/ friend class UniPrint;

public:
  using size_type = int;
  using value_type = typename std::vector<T>::value_type;
  using reference = typename std::vector<T>::reference;
  using const_reference = typename std::vector<T>::const_reference;

private:
  std::vector<T> heap_;

public:
  PQComplHeap() = default;

  PQComplHeap(T* arr, size_type n) : heap_(arr + 0, arr + n) { heapify(heap_, n); }

  ~PQComplHeap() = default;

  /*DSA*/
  reference operator[](size_type pos) { return heap_[pos]; }

  /*DSA*/
  const_reference operator[](size_type pos) const { return heap_[pos]; }

  size_type size() const { return heap_.size(); }

  bool empty() const { return heap_.empty(); }

  //按照比较器确定的优先级次序，插入词条
  void insert(const T& value) override {
    heap_.push_back(value);
    if(size() == 0)
      return;
    percolateUp(heap_, heap_.size() - 1);
  }

  //取出最大词条
  T delMax() override {
    //堆顶、堆尾互换（_size的递减，不致引发shrink()）
    value_type val{};
    if(size() == 0)
      return val;
    val = heap_[0];
    using std::swap;
    swap(heap_[0], heap_[size() - 1]);
    heap_.pop_back();
    //新堆顶下滤
    percolateDown(heap_, size(), 0);
    //返回原堆顶
    return val;
  }

  //读取优先级最高的词条
  T& getMax() override { return heap_[0]; }
};

#endif  //  PQ_COMPL_HEAP_HPP