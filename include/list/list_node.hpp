#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

using Rank = int;

#define ListNodePosi(T) ListNode<T>*

template<class T>
struct ListNode {
  using self = ListNode<T>;
  using iterator = ListNodePosi(T);
  using const_iterator = const ListNodePosi(T);

  T data;         // 数据
  iterator prev;  // 前驱指针
  iterator next;  // 后继指针

  ListNode() : data(), prev(nullptr), next(nullptr) {}

  ListNode(const T& value, iterator p = nullptr, iterator n = nullptr)
      : data(value), prev(p), next(n) {}

  // 在当前调用节点之前插入新结点
  iterator insertAsPrev(const T& value) {
    iterator x = new self(value, prev, this);
    prev->next = x;
    prev = x;
    return x;
  }

  // 在当前调用节点之后插入新结点
  iterator insertAsNext(const T& value) {
    iterator x = new self(value, this, next);
    next->prev = x;
    next = x;
    return x;
  }

  ListNodePosi(T) operator++() {
    this = this->next;
    return this;
  }

  ListNodePosi(T) operator++(int) {
    ListNodePosi(T) ret = this;
    this = this->next;
    return ret;
  }

  ListNodePosi(T) operator--() {
    this = this->prev;
    return this;
  }

  ListNodePosi(T) operator--(int) {
    ListNodePosi(T) ret = this;
    this = this->prev;
    return ret;
  }
};

#endif  // LIST_NODE_HPP