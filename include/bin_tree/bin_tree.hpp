#ifndef BIN_TREE_HPP
#define BIN_TREE_HPP

#include <memory>

#include "bin_node.hpp"

template<typename T>
class BinTree {
  friend bool operator<(const BinTree<T>&, const BinTree<T>&);
  friend bool operator==(const BinTree<T>&, const BinTree<T>&);

public:
  using self = BinTree<T>;
  using size_type = typename BinNode<T>::size_type;
  using iterator = BinNodePosi(T);
  using const_iterator = const BinNodePosi(T);

protected:
  iterator root_;  // 根节点
  size_type size_;

private:
  iterator nodeCopy(iterator parent, iterator pos) {
    if(!pos)
      return nullptr;
    iterator t = new BinNode<T>(pos->data, parent, nullptr, nullptr,
                                pos->height, pos->npl, pos->color);
    t->l_child = nodeCopy(t, pos->l_child);
    t->r_child = nodeCopy(t, pos->r_child);
    return t;
  }

  //删除二叉树中位置x处的节点及其后代，返回被删除节点的个数
  size_type removeAt(iterator pos) {
    if(!pos)
      return 0;
    size_type cnt = 1 + removeAt(pos->l_child) + removeAt(pos->r_child);
    delete pos;
    pos = nullptr;
    return cnt;
  }

public:
  BinTree() : root_(nullptr), size_(0) {}

  BinTree(const BinTree& other) {
    root_ = nodeCopy(nullptr, other.root_);
    size_ = other.size_;
  }

  virtual ~BinTree() {
    if(root_)
      removeAt(root_);
  }

  iterator& root() { return root_; }

  const_iterator& root() const { return root_; }

  size_type size() const { return size_; }

  bool empty() const { return !root_; }

  size_type height(const_iterator pos) const {
    if(!pos)
      return 0;
    return pos->height;
  }

  // 插入根节点
  iterator insertRoot(const T& value) {
    size_ = 1;
    return root_ = new BinNode<T>(value);
  }

  // 将value作为pos的左孩子插入
  iterator insertLC(iterator pos, const T& value) {
    ++size_;
    pos = pos->insertLC(value);
    pos->updateHeightAbove();
    return pos;
  }

  // 将value作为pos的右孩子插入
  iterator insertRC(iterator pos, const T& value) {
    ++size_;
    pos = pos->insertRC(value);
    pos->updateHeightAbove();
    return pos;
  }

  // 将t作为pos节点的左子树接入
  iterator attachLC(iterator pos, BinTree<T>& t) {
    pos->l_child = t.root_;
    if(!hasLChild(pos))
      return pos;
    pos->l_child->parent = pos;
    size_ += t.size_;
    pos->updateHeightAbove();
    t.root_ = nullptr;
    t.size_ = 0;
    return pos;
  }

  // 将t作为pos节点的右子树接入
  iterator attachRC(iterator pos, BinTree<T>& t) {
    pos->r_child = t.root_;
    if(!hasRChild(pos))
      return pos;
    pos->r_child->parent = pos;
    size_ += t.size_;
    pos->updateHeightAbove();
    t.root_ = nullptr;
    t.size_ = 0;
    return pos;
  }

  //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
  size_type remove(iterator pos) {
    fromParentTo(pos) = nullptr;       //切断来自父节点的指针
    pos->parent->updateHeightAbove();  //更新祖先高度
    size_type cnt = removeAt(pos);
    size_ -= cnt;
    return cnt;  //删除子树x，更新规模，返回删除节点总数
  }

  //二叉树子树分离算法：将子树x从当前树中摘除，将其封装为一棵独立子树返回
  std::unique_ptr<BinTree<T>> secede(iterator pos) {
    fromParentTo(pos) = nullptr;       //切断来自父节点的指针
    pos->parent->updateHeightAbove();  //更新原树中所有祖先的高度
    auto S = std::make_unique<BinTree<T>>();
    S->root_ = pos;
    pos->parent = nullptr;  //新树以x为根
    S->size_ = pos->size();
    size_ -= S->size_;
    return S;  //更新规模，返回分离出来的子树
  }

  template<typename Fn>
  void travPrev(Fn&& fn) {
    if(root_)
      root_->travPrev(std::forward<Fn>(fn));
  }

  template<typename Fn>
  void travIn(Fn&& fn) {
    if(root_)
      root_->travIn(std::forward<Fn>(fn));
  }

  template<typename Fn>
  void travPost(Fn&& fn) {
    if(root_)
      root_->travPost(std::forward<Fn>(fn));
  }

  template<typename Fn>
  void travLevel(Fn&& fn) {
    if(root_)
      root_->travLevel(std::forward<Fn>(fn));
  }
};

template<typename T>
bool
operator<(const BinTree<T>& x, const BinTree<T>& y) {
  return x.root_ && y.root_ && (x.root_ < y.root_);
}

template<typename T>
bool
operator==(const BinTree<T>& x, const BinTree<T>& y) {
  return x.root_ && y.root_ && (x.root_ == y.root_);
}

#endif  // BIN_TREE_HPP