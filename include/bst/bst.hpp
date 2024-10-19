#ifndef BST_HPP
#define BST_HPP

#include <cstdio>

#include "bin_tree.hpp"

template<typename T>
class BST : public BinTree<T> {
public:
  using iterator = typename BinTree<T>::iterator;
  using const_iterator = typename BinTree<T>::const_iterator;

protected:
  iterator hot_;  //“命中”节点的父亲

  /*
 * BST节点删除算法：删除位置x所指的节点（全局静态模板函数，适用于AVL、Splay、RedBlack等各种BST）
 * 目标x在此前经查找定位，并确认非NULL，故必删除成功；与searchIn不同，调用之前不必将hot置空
 * 返回值指向实际被删除节点的接替者，hot指向实际被删除节点的父亲——二者均有可能是NULL
 */
  iterator removeAt(iterator& pos) {
    iterator w = pos;             //实际被摘除的节点，初值同x
    iterator next = nullptr;      //实际被删除节点的接替者
    if(!pos->l_child)             //若pos的左子树为空，则可
      next = pos = pos->r_child;  //直接将pos替换为其右子树
    else if(!pos->r_child)        //若右子树为空，则可
      next = pos = pos->l_child;  //对称地处理——注意：此时succ != NULL
    else {  //若左右子树均存在，则选择pos的直接后继作为实际被摘除节点，为此需要
      w = w->next();  //（在右子树中）找到pos的直接后继w
      using std::swap;
      swap(pos->data, w->data);  //交换pos和w的数据元素
      iterator u = w->parent;
      ((u == pos) ? u->r_child : u->l_child) = next = w->r_child;  //隔离节点w
    }
    hot_ = w->parent;  //记录实际被删除节点的父亲
    if(next)
      next->parent = hot_;  //并将被删除节点的接替者与hot相联
    delete w;
    return next;  //释放被摘除节点，返回接替者
  }

  /*
 * 按照“3 + 4”结构联接3个节点及其四棵子树，返回重组之后的局部子树根节点位置（即b）
 * 子树根节点与上层节点之间的双向联接，均须由上层调用者完成
 * 可用于AVL和RedBlack的局部平衡调整
 */
  iterator connect34(iterator a, iterator b, iterator c, iterator T0,
                     iterator T1, iterator T2, iterator T3) {
    /*DSA*/  //print(a); print(b); print(c); printf("\n");
    a->l_child = T0;
    if(T0)
      T0->parent = a;
    a->r_child = T1;
    if(T1)
      T1->parent = a;
    a->updateHeight();
    c->l_child = T2;
    if(T2)
      T2->parent = c;
    c->r_child = T3;
    if(T3)
      T3->parent = c;
    c->updateHeight();
    b->l_child = a;
    a->parent = b;
    b->r_child = c;
    c->parent = b;
    b->updateHeight();
    return b;  //该子树新的根节点
  }

  /*
 * BST节点旋转变换统一算法（3节点 + 4子树），返回调整之后局部子树根节点的位置
 * 注意：尽管子树根会正确指向上层节点（如果存在），但反向的联接须由上层函数完成
 */
  //v为非空孙辈节点
  iterator rotateAt(iterator v) {
    /*DSA*/ if(!v) {
      printf("\a\nFail to rotate a null node\n");
      exit(-1);
    }
    iterator p = v->parent;
    int TurnV = (v == p->r_child);
    iterator g = p->parent;
    int TurnP = (p == g->r_child);
    //子树新的根节点
    iterator r = (TurnP == TurnV) ? p : v;
    //须保持与母树的联接
    (fromParentTo(g) = r)->parent = g->parent;
    switch((TurnP << 1) | TurnV) {  //视p、v的拐向，无非四种情况
      case 0b00:                    //zig-zig
        return connect34(v, p, g, v->l_child, v->r_child, p->r_child, g->r_child);
      case 0b01:  //zig-zag
        return connect34(p, v, g, p->l_child, v->l_child, v->r_child, g->r_child);
      case 0b10:  //zag-zig
        return connect34(g, v, p, g->l_child, v->l_child, v->r_child, p->r_child);
      default:  //0b11 ~ zag-zag
        return connect34(g, p, v, g->l_child, p->l_child, v->l_child, v->r_child);
    }
  }

public:
  //基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写

  //在BST中查找关键码value
  //无论命中或失败，hot_均指向v之父亲（v是根时，hot为NULL）
  virtual iterator& search(const T& value) {
    //空树，或恰在树根命中
    if(!this->root_ || value == this->root_->data) {
      hot_ = nullptr;
      return this->root_;
    }
    //否则，自顶而下
    for(hot_ = this->root_;;) {
      //确定方向，深入一层
      iterator& v = (value < hot_->data) ? hot_->l_child : hot_->r_child;
      if(!v || value == v->data)
        return v;
      hot_ = v;  //一旦命中或抵达叶子，随即返回
    }
  }

  //将关键码value插入BST树中
  //无论value是否存在于原树中，返回时总有pos->data == e
  virtual iterator insert(const T& value) {
    iterator& pos = search(value);
    if(pos)
      return pos;
    //确认目标不存在，并设置_hot
    pos = new BinNode<T>(value, hot_);  //在x处创建新节点，以_hot为父
    ++this->size_;
    pos->updateHeightAbove();  //更新全树规模，以及历代祖先的高度
    return pos;                //新插入的节点，必为叶子
  }

  //从BST树中删除关键码value
  //删除成功与否，由返回值指示
  virtual bool remove(const T& value) {
    iterator& pos = search(value);
    if(!pos)
      return false;  //确认目标存在（留意_hot的设置）
    removeAt(pos);   //实施删除
    --this->size_;
    hot_->updateHeightAbove();  //更新全树高度，以及历代祖先的高度
    return true;
  }

  //借助zag旋转，转化为左向单链
  void stretchToLPath() { stretchByZag(this->root_); }

  //借助zig旋转，转化为右向单链
  void stretchToRPath() { stretchByZig(this->root_); }

  void stretch();

  void balance() {}

  void imitate() {}
};
#endif  // BST_HPP