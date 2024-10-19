#ifndef AVL_HPP
#define AVL_HPP

#include "bst.hpp"

// define begin
// clang-format off

/*
 * 在左、右孩子中取更高者
 * 在AVL平衡调整前，借此确定重构方案
 */
#define tallerChild(pos) ( \
  stature((pos)->l_child) > stature( (pos)->r_child ) \
    ? (pos)->l_child \
    : (stature((pos)->l_child) < stature((pos)->r_child) \
      ? (pos)->r_child \
      : ((((pos)->parent) && ((pos) == (pos)->l_child)) \
        ? (pos)->l_child \
        : (pos)->r_child)) \
)

// clang-format on
// define end

template<typename T>
class AVL : public BST<T> {  //由BST派生AVL树模板类
public:
  using size_type = typename BST<T>::size_type;
  using iterator = BinNodePosi(T);
  using const_iterator = const BinNodePosi(T);

  //将关键码value插入AVL树中
  iterator insert(const T& value) {
    iterator& pos = this->search(value);
    if(pos)
      return pos;
    //创建新节点x
    iterator it = pos = new BinNode<T>(value, this->hot_);
    ++this->size_;
    // 此时，pos的父亲hot_若增高，则其祖父有可能失衡
    //逐层上溯
    for(iterator g = this->hot_; g; g->updateHeight(), g = g->parent)
      //一旦发现失衡祖先g，则
      if(!AVLBalanced(g)) {
        //（采用“3+4”算法）使之复衡
        this->rotateAt(tallerChild(tallerChild(g)));
        break;  //并随即终止（局部子树复衡后，高度必然复原；所有祖先亦必复衡）
      }
    return it;
  }

  //从AVL树中删除关键码value
  bool remove(const T& value) {
    iterator& pos = this->search(value);
    if(!pos)
      return false;
    this->removeAt(pos);
    //先按BST规则删除之（此后，原节点之父_hot及其祖先均可能失衡）
    --this->size_;
    //逐层上溯
    for(iterator g = this->hot_; g; g->updateHeight(), g = g->parent)
      if(!AVLBalanced(g))  //每当发现失衡祖先g，都
        this->rotateAt(tallerChild(tallerChild(g)));  //（采用“3+4”算法）使之复衡
    return true;                                //删除成功
  }

  // BST::search()等其余接口可直接沿用
};

#endif  //  AVL_HPP