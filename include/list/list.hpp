#ifndef LIST_HPP
#define LIST_HPP

#include <cassert>
#include <functional>
#include <utility>

#include "list_node.hpp"

enum class InsertType : int { INSERT_BEFORE, INSERT_AFTER };

template<class T>
class List {
public:
  using value_type = T;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = T&;
  using const_reference = const T&;
  using pointer = T*;
  using const_pointer = const T*;
  using iterator = ListNodePosi(T);
  using const_iterator = const ListNodePosi(T);

private:
  size_type size_;
  iterator header_;
  iterator tailer_;

protected:
  void init() {
    size_ = 0;
    header_ = new ListNode<T>;
    tailer_ = new ListNode<T>;
    header_->prev = nullptr;
    header_->next = tailer_;
    tailer_->prev = header_;
    tailer_->next = nullptr;
  }

  // 复制列表中从位置pos开始的n个项
  void copyNodes(const_iterator pos, int n) {
    this->init();
    for(int i = 0; i != n; ++i) {
      this->pushBack(pos->data);
      pos = pos->next;
    }
  }

  // 将other中自q起的n2个元素，与自p起的n1个元素合并，默认升序
  // 考虑other与this是同一个列表的情况
  template<typename Cmp>
  void merge(ListNodePosi(T) p, size_type n1, List<T>& other, ListNodePosi(T) q,
             size_type n2) {
    while(0 < n2) {
      if((0 < n1)
         && (Cmp()(p->data, q->data))) {  // p还在区间内或者p->data > q->data
        p = p->next;
        if(q == p)
          break;
        --n1;
      } else {  // p超出右界
        q = q->next;
        this->insert(p, other.remove(q->prev), InsertType::INSERT_BEFORE);
        --n2;
      }
    }
  }

  // 对从p开始连续的n个节点选择排序
  void selectSort(ListNodePosi(T) pos, int n) {}

  // 对从p开始连续的n个节点插入排序
  void insertSort(ListNodePosi(T) pos, int n) {
    for(int i = 0; i != n; ++i) {
      insert(search(pos->data, i, pos), pos->data, InsertType::INSERT_AFTER);
      pos = pos->next;
      erase(pos->prev);
    }
  }

public:
  List() : size_(0), header_(nullptr), tailer_(nullptr) { this->init(); }

  List(const List<T>& list) : List(list.begin(), list.size()) {}

  // 从位置pos处开始复制n个结点
  List(const_iterator pos, int n) { this->copyNodes(pos, n); }

  ~List() {
    this->clear();
    if(header_) {
      delete header_;
      header_ = nullptr;
    }
    if(tailer_) {
      delete tailer_;
      tailer_ = nullptr;
    }
  }

  //重载下标操作符，以通过秩直接访问列表节点（虽方便，效率低，需慎用）
  //assert: 0 <= r < size
  reference operator[](size_type r) {
    iterator cit = begin();
    while(0 < r--)
      cit = cit->next;  //顺数第r个节点即是
    return cit->data;   //目标节点，返回其中所存元素
  }

  const_reference operator[](size_type r) const {
    const_iterator cit = begin();
    while(0 < r--)
      cit = cit->next;  //顺数第r个节点即是
    return cit->data;   //目标节点，返回其中所存元素
  }

  reference front() { return this->begin()->data; }

  const_reference front() const { return this->begin()->data; }

  reference back() { return this->end()->prev->data; }

  const_reference back() const { return this->end()->prev->data; }

  iterator begin() { return header_->next; }

  const_iterator begin() const { return header_->next; }

  iterator end() { return tailer_; }

  const_iterator end() const { return tailer_; }

  size_type size() const { return size_; }

  bool empty() const { return size_ <= 0; }

  // 清空结点
  void clear() {
    while(size_ > 0)
      this->erase(header_->next);
  }

  // 默认pos后一个位置插入
  iterator insert(iterator pos, const T& value, InsertType type) {
    ++size_;
    if(type == InsertType::INSERT_BEFORE)
      return pos->insertAsPrev(value);
    else
      return pos->insertAsNext(value);
  }

  iterator insertAsFront(const T& value) {
    ++size_;
    return header_->insertAsNext(value);
  }

  iterator insertAsBack(const T& value) {
    ++size_;
    return tailer_->insertAsPrev(value);
  }

  // 删除合法范围[first, last)
  // void erase(ListNodePosi(T) first, ListNodePosi(T) last) {}

  iterator erase(iterator pos) {
    iterator ret = pos->next;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    if(pos) {
      delete pos;
      pos = nullptr;
    }
    --size_;
    return ret;
  }

  void pushBack(const T& value) {
    ++size_;
    tailer_->insertAsPrev(value);
  }

  void popBack() { this->erase(tailer_->prev); }

  void pushFront(const T& value) {
    ++size_;
    header_->insertAsNext(value);
  }

  void popFront() { this->erase(header_->next); }

  // 归并两个已经有序的列表，默认升序
  template<typename Cmp = std::less<T>>
  void merge(List<T>& other) {
    this->merge<Cmp>(this->begin(), size_, other, other.begin(), other.size_);
  }

  template<typename Cmp = std::less<T>>
  void merge(List<T>& other, ListNodePosi(T) pos, size_type n) {
    this->merge<Cmp>(this->begin(), size_ - n, other, pos, n);
  }

  // void sort() {}

  // 无序去重，返回删除元素个数
  size_type deduplicate() {
    if(size_ < 2)
      return 0;
    size_type old_size = size_;
    iterator p = begin();
    Rank r = 0;
    iterator q = nullptr;
    for(; p != tailer_; p = p->next) {
      q = this->find(p->data, r, p);
      (header_ != q) ? this->remove(q) : ++r;
    }  // 每次都把当前元素与前面所有元素进行对比
    return old_size - size_;
  }

  value_type remove(iterator pos) {
    value_type val = pos->data;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    if(pos) {
      delete pos;
      pos = nullptr;
    }
    --size_;
    return val;
  }

  //前后倒置
  void reverse() {
    iterator p = header_;
    iterator q = tailer_->prev;
    for(; p != q; p = p->next, q = q->prev) {
      std::swap(p->data, q->data);
    }
  }

  // 有序去重
  size_type unique() {
    if(size_ < 2)
      return 0;
    size_type old_size = size_;
    iterator q = begin();
    iterator p = q->next;
    for(; q != tailer_; q = p->next) {
      if(q->data != p->data)
        p = q;
      else
        this->erase(q);
    }  // p在前，q在后
    return old_size - size_;
  }

  //列表区间排序
  void sort(iterator pos, int n) {
    insertSort(pos, n);
  }

  //列表整体排序
  void sort() { sort(begin(), size_); }

  void traverse(void (*fn)(T&)) {
    iterator p = header_;
    while((p = p->next) != tailer_)
      fn(p->data);
  }

  template<typename Fn>
  void traverse(Fn&& fn) {
    iterator p = header_;
    while((p = p->next) != tailer_)
      fn(p->data);
  }

  // 判断位置p是否对外合法
  bool valid(const_iterator pos) const {
    return pos && (header_ != pos) && (tailer_ != pos);
  }

  // [p + 1, p + n)
  const_iterator selectMax(const_iterator p, size_type n) {
    const_iterator max = p;
    const_iterator curr = p;
    for(int i = 1; i != n; ++i) {
      ++curr;
      if(curr->data >= max->data)  // 同大时取秩最大
        max = curr;
    }
    return max;
  }

  // 判断列表是否已排序
  size_type disordered() const {
    size_type cnt = 0;
    const_iterator it = begin();
    if(!valid(it))
      return cnt;
    for(size_type i = 0; i != size_ - 1; it = it->next, ++i) {
      if(it->data > it->next->data)
        ++cnt;
    }
    return cnt;
  }

  iterator find(const T& value) { return this->find(value, size_, tailer_); }

  const_iterator find(const T& value) const {
    return this->find(value, size_, tailer_);
  }

  // 在列表内节点pos（可能是tailer_）的count个（真）前驱中，找到第一个value
  iterator find(const T& value, Rank count, iterator pos) {
    for(; count >= 0; --count) {
      pos = pos->prev;
      if(value == pos->data)
        break;
    }
    return pos;
  }

  const_iterator find(const T& value, Rank count, const_iterator pos) const {
    for(; count >= 0; --count) {
      pos = pos->prev;
      if(value == pos->data)
        break;
    }
    return pos;
  }

  iterator search(const T& value) {
    return this->search(value, size_, tailer_);
  }

  const_iterator search(const T& value) const {
    return this->search(value, size_, tailer_);
  }

  // 在列表内节点pos（可能是tailer_）的count个（真）前驱中，找到第一个大于等于value
  iterator search(const T& value, Rank count, iterator pos) {
    for(; count >= 0; --count) {
      pos = pos->prev;
      if(value >= pos->data)
        break;
    }
    return pos;
  }

  const_iterator search(const T& value, Rank count, const_iterator pos) const {
    for(; count >= 0; --count) {
      pos = pos->prev;
      if(value >= pos->data)
        break;
    }
    return pos;
  }

  // ListNodePosi(T) selectMax(ListNodePosi(T) pos, int n) {}
};

#endif  // LIST_HPP