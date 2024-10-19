#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cassert>
#include <cstdlib>
#include <functional>
#include <utility>

#define DEFAULT_CAPACITY 2

template<class T>
class Vector {
public:
  using value_type = T;
  using size_type = std::size_t;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using rank = int;

private:
  iterator begin_;
  iterator end_;
  iterator end_cap_;

  void init(size_type n) {
    end_ = begin_ = new T[n]{};
    end_cap_ = end_ + n;
  }

  void free() {
    if(begin_) {
      delete[] begin_;
      begin_ = end_ = end_cap_ = nullptr;
    }
  }

  // 在[first, last)中使用二分查找数据x
  // 若查找的元素有多个相同的情况，则可以找到此元素的最大秩
  rank binSearch(const T& value, rank first, rank last) const {
    rank m{};
    while(first < last) {
      m = (first + last) / 2;
      (value < begin_[m]) ? last = m : first = m + 1;
    }
    return --first;
  }

protected:
  // 基于数组复制
  void copyFrom(const_iterator arr, size_type n, rank first, rank last) {
    this->free();
    this->init(n);
    while(first < last)
      *end_++ = arr[first++];
  }

  // 空间不足时，扩容向量
  void expand(size_type n) {
    if((end_ + n) <= end_cap_)
      return;
    iterator old_begin = begin_;
    iterator old_end = end_;
    iterator old_end_cap = end_cap_;
    begin_ = end_ = end_cap_ = nullptr;
    this->copyFrom(old_begin, 2 * (old_end - old_begin), 0,
                   (old_end - old_begin));
    if(old_begin) {
      delete[] old_begin;
      old_begin = old_end = old_end_cap = nullptr;
    }
  }

  // 装填因子过小时压缩向量所占空间
  void shrink() {
    if(this->capacity() < DEFAULT_CAPACITY / 2)
      return;
    if(this->size() * 4 > this->capacity())
      return;
    iterator old_begin = begin_;
    iterator old_end = end_;
    iterator old_end_cap = end_cap_;
    begin_ = end_ = end_cap_ = nullptr;
    this->copyFrom(old_begin, (old_end_cap - old_begin) / 2, 0,
                   (old_end - old_begin));
    if(old_begin) {
      delete[] old_begin;
      old_begin = old_end = old_end_cap = nullptr;
    }
  }

  // 冒泡排序
  template<typename Cmp>
  void bubbleSort(rank first, rank last) {
    rank i = first;
    while(true) {
      bool is_swap = false;
      while(++i < last) {
        if(Cmp()(begin_[i], begin_[i - 1])) {
          is_swap = true;
          using std::swap;
          swap(begin_[i - 1], begin_[i]);
        }
      }
      --last;
      i = first;
      if(!is_swap)
        break;
    }
  }

  template<typename Cmp>
  void merge(iterator tmp_arr, size_type first, size_type mid, size_type last) {
    iterator arr1 = begin_ + first;
    size_type size1 = mid - first;
    for(size_type i = 0; i != size1; ++i)
      tmp_arr[i] = arr1[i];
    size_type size2 = last - mid;
    iterator arr2 = begin_ + mid;
    size_type i(0), j(0), k(0);  // arr1->i tmp_arr->j arr2->k
    while((j < size1) && (k < size2)) {
      while((j < size1) && Cmp()(tmp_arr[j], arr2[k]))  // tmp_arr[j] <= arr2[k]
        arr1[i++] = tmp_arr[j++];
      while((k < size2) && Cmp()(arr2[k], tmp_arr[j]))  // arr2[k] <= tmp_arr[j]
        arr1[i++] = arr2[k++];
    }
    while(j < size1)
      arr1[i++] = tmp_arr[j++];
  }

  // 归并排序[l, h)
  template<typename Cmp>
  void mergeSort(iterator tmp_arr, rank first, rank last) {
    if(last - first < 2)
      return;
    rank m = (first + last) / 2;
    this->mergeSort<Cmp>(tmp_arr, first, m);
    this->mergeSort<Cmp>(tmp_arr, m, last);
    this->merge<Cmp>(tmp_arr, first, m, last);
  }

  // 轴点构造
  // rank partition(rank l, rank h) {}

  // 快速排序
  void quickSort(rank l, rank h) {}

  // 堆排序
  void heapSort(rank l, rank h) {}

public:
  Vector(size_type n = DEFAULT_CAPACITY)
      : begin_(nullptr), end_(nullptr), end_cap_(nullptr) {
    this->init(n);
  }

  Vector(const_iterator arr, rank first, rank last)
      : begin_(nullptr), end_(nullptr), end_cap_(nullptr) {
    this->copyFrom(arr, last - first, first, last);
  }

  Vector(const_iterator arr, size_type n)
      : begin_(nullptr), end_(nullptr), end_cap_(nullptr) {
    this->copyFrom(arr, n, 0, n);
  }

  Vector(const Vector& other, rank first, rank last)
      : begin_(nullptr), end_(nullptr), end_cap_(nullptr) {
    this->copyFrom(other.begin_, last - first, first, last);
  }

  Vector(const Vector& other)
      : begin_(nullptr), end_(nullptr), end_cap_(nullptr) {
    this->copyFrom(other.begin_, other.size(), 0, other.size());
  }

  ~Vector() { this->free(); }

  Vector& operator=(const Vector& other) {
    if(&other != this) {
      rank n = other.size();
      if(this->capacity() < n)
        copyFrom(other.begin_, 2 * n, 0, n);
      else
        copyFrom(other.begin_, n, 0, n);
    }
    return *this;
  }

  reference at(size_type pos) {
    assert((pos < this->size()) && (pos >= 0));
    return begin_[pos];
  }

  const_reference at(size_type pos) const {
    assert((pos < this->size()) && (pos >= 0));
    return begin_[pos];
  }

  reference operator[](size_type pos) { return begin_[pos]; }

  const_reference operator[](size_type pos) const { return begin_[pos]; }

  reference front() { return *begin_; }

  const_reference front() const { return *begin_; }

  reference back() { return *(end_ - 1); }

  const_reference back() const { return *(end_ - 1); }

  iterator begin() { return begin_; }

  const_iterator begin() const { return begin_; }

  iterator end() { return end_; }

  const_iterator end() const { return end_; }

  bool empty() const { return (end_ - begin_) <= 0; }

  size_type size() const { return end_ - begin_; }

  size_type capacity() const { return end_cap_ - begin_; }

  iterator insert(iterator pos, const T& value) {
    if(pos > end_)
      return nullptr;
    size_type n = pos - begin_;
    this->expand(1);
    iterator it = end_;
    pos = begin_ + n;
    end_ += 1;
    for(; pos != it; --it)
      *it = *(it - 1);
    *pos = value;
    return pos;
  }

  // 区间删除 [first, last)
  iterator erase(iterator first, iterator last) {
    if(first >= last)
      return nullptr;
    size_type n = first - begin_;
    while(last != end_) {
      *first = *last;
      ++first;
      ++last;
    }
    end_ = first;
    this->shrink();
    return (begin_ + n);
  }

  iterator erase(iterator pos) { return this->erase(pos, pos + 1); }

  void pushBack(const T& value) { this->insert(end_, value); }

  void popBack() { this->erase(end_ - 1); }

  void swap(Vector<T>& other) {
    if(this == &other)
      return;
    iterator old_begin = other.begin_;
    iterator old_end = other.end_;
    iterator old_end_cap = other.end_cap_;
    other.begin_ = begin_;
    other.end_ = end_;
    other.end_cap_ = end_cap_;
    begin_ = old_begin;
    end_ = old_end;
    end_cap_ = old_end_cap;
    old_begin = old_end = old_end_cap = nullptr;
  }

  // 区间删除 [l, h)
  size_type remove(size_type first, size_type last) {
    if(first >= last)
      return 0;
    while(last < this->size())
      begin_[first++] = begin_[last++];
    end_ = begin_ + first;
    this->shrink();
    return last - first;
  }

  // 单元素删除
  value_type remove(rank r) {
    value_type ret = begin_[r];
    remove(r, r + 1);
    return ret;
  }

  // 查找[l, h)范围内的数据,返回最后一个等于x的元素的位置
  rank find(const T& value, rank first, rank last) const {
    for(; (first < last) && (begin_[--last] != value);)
      ;
    return last;
  }

  rank find(const T& value) const { return this->find(value, 0, this->size()); }

  //有序向量整体查找
  size_type search(const T& value) const {
    return (0 >= size()) ? -1 : search(value, 0, size());
  }

  // 在有序向量的区间[l, h)内，确定不大于x的最后一个节点位置
  rank search(const T& value, rank first, rank last) const {
    return binSearch(value, first, last);
  }

  // 随机置乱器
  void permute(Vector<T>& other) {
    for(rank i = 0; i != other.size(); --i) {
      using std::swap;
      swap(other[i - 1], other[rand() % i]);
    }
  }

  // 区间置乱器 [l, h)
  void unsort(rank first, rank last) {
    if(first > last)
      return;
    T* vec = begin_ + first;
    for(rank i = last - first; i > 0; --i) {
      using std::swap;
      swap(vec[i - 1], vec[rand() % i]);
    }
  }

  void unsort() { this->unsort(0, this->size()); }

  // 排序[l, h)区间,默认升序
  template<typename Cmp = std::less_equal<T>>
  void sort(std::size_t selector, rank first, rank last) {
    switch(selector) {
      case 0:
        bubbleSort<Cmp>(first, last);
        break;
      case 1:
        iterator tmp_arr = new T[this->size()]{};
        this->mergeSort<Cmp>(tmp_arr, first, last);
        if(tmp_arr) {
          delete[] tmp_arr;
          tmp_arr = nullptr;
        }
        break;
    }
  }

  // 默认以快速排序为主，升序
  void sort() { this->sort(1, 0, this->size()); }

  // 删除无序向量中重复的元素，返回删除元素个数
  size_type deduplicate() {
    size_type old_size = this->size();
    size_type i = 1;
    size_type j = 0;
    while(i < this->size()) {
      j = this->find(begin_[i], 0, i);
      (0 == j) ? ++i : this->remove(j);
    }
    return old_size - this->size();
  }

  // 删除有序向量中重复的元素，返回删除元素个数
  size_type unique() {
    if(this->size() < 2)
      return 0;
    rank i = 0, j = 1;
    for(; j != this->size(); ++j) {
      if(begin_[i] != begin_[j])
        begin_[++i] = begin_[j];
    }
    end_ = begin_ + ++i;
    this->shrink();
    return j - i;
  }

  void traverse(void (*fn)(T&)) {
    for(size_type i = 0; i != this->size(); ++i)
      fn(begin_[i]);
  }

  // 遍历向量
  template<typename Fn>
  void traverse(Fn&& fn) {
    for(size_type i = 0; i != this->size(); ++i)
      fn(begin_[i]);
  }
};
#endif  // VECTOR_HPP