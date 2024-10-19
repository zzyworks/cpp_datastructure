#ifndef BIN_NODE_HPP
#define BIN_NODE_HPP

#include <algorithm>
#include <queue>
#include <utility>

template<class T>
struct BinNode;
#define BinNodePosi(T) BinNode<T>*
template<class T>
using iterator = BinNodePosi(T);
template<class T>
using const_iterator = const BinNodePosi(T);

enum class RBColor : int { RB_RED, RB_BLACK };

// BinNode状态与性质的判断

// 是否为根节点
template<typename T>
inline bool
isRoot(const_iterator<T> it) {
  return !(it->parent);
}

// 是否为左孩子
template<typename T>
inline bool
isLChild(const_iterator<T> it) {
  return (it && (it == it->parent->l_child));
}

// 是否为右孩子
template<typename T>
inline bool
isRChild(const_iterator<T> it) {
  return (it && (it == it->parent->r_child));
}

// 是否有父节点
template<typename T>
inline bool
hasParent(const_iterator<T> it) {
  return (!isRoot(it));
}

// 是否有左孩子
template<typename T>
inline bool
hasLChild(const_iterator<T> it) {
  return (it->l_child);
}

// 是否有右孩子
template<typename T>
inline bool
hasRChild(const_iterator<T> it) {
  return (it->r_child);
}

// 是否有孩子
template<typename T>
inline bool
hasChild(const_iterator<T> it) {
  return (hasLChild(it) || hasRChild(it));
}

// 是否同时有两个孩子
template<typename T>
inline bool
hasBothChild(const_iterator<T> it) {
  return (hasLChild(it) && hasRChild(it));
}

// 是否为叶子节点
template<typename T>
inline bool
isLeaf(const_iterator<T> it) {
  return (!hasChild(it));
}

// 与BinNode具有特定关系的节点及指针

// 当前节点是否有兄弟节点
template<typename T>
inline bool
silbling(const_iterator<T> it) {
  return (isLChild(it) ? it->parent->r_child : it->parent->l_child);
}

// 当前节点是否有叔叔节点
template<typename T>
inline bool
uncle(const_iterator<T> it) {
  return isLChild(it->parent) ? it->parent->parent->r_child
                              : it->parent->parent->l_child;
}

template<typename T>
int
getHeight(iterator<T> pos) {
  int lh(0), rh(0);
  if(!pos)
    return -1;
  else if(!hasBothChild(pos))
    return 0;
  else {
    lh = getHeight(pos->l_child) + 1;
    rh = getHeight(pos->r_child) + 1;
  }
  return lh > rh ? lh : rh;
}

template<typename T, typename Fn>
void
travPrevR(iterator<T> pos, Fn&& fn) {
  if(!pos)
    return;
  fn(pos->data);
  travPrevR(pos->l_child, fn);
  travPrevR(pos->r_child, fn);
}

template<typename T, typename Fn>
void
travInR(iterator<T> pos, Fn&& fn) {
  if(!pos)
    return;
  travInR(pos->l_child, fn);
  fn(pos->data);
  travInR(pos->r_child, fn);
}

template<typename T, typename Fn>
void
travPostR(iterator<T> pos, Fn&& fn) {
  if(!pos)
    return;
  travPostR(pos->l_child, fn);
  travPostR(pos->r_child, fn);
  fn(pos->data);
}

// define begin
// clang-format off

#define fromParentTo(pos) /*来自父亲的引用*/ \
   ((pos)->parent ? (((pos) == (pos)->parent->l_child) \
                    ? (pos)->parent->l_child  \
                    : (pos)->parent->r_child ) \
                  : this->root_)

#if defined(DSA_RED_BLACK)                  //在红黑树中
#define stature(p) ((p) ? (p)->height : 0)  //外部节点（黑）高度为0，以上递推
#else                                       //其余BST中
#define stature(pos) \
  ((int)((pos) ? (pos)->height : -1))  //外部节点高度为-1，以上递推
#endif

/*高度更新常规条件*/
/*DSA*/
#define heightUpdated(pos) \
  ((pos)->height == 1 + std::max(stature((pos)->l_child), stature((pos)->r_child)))
//理想平衡条件
#define balanced(pos) (stature((pos)->l_child) == stature((pos)->r_child))
//平衡因子
#define balFac(pos) (stature((pos)->l_child) - stature((pos)->r_child))
// AVL平衡条件
#define AVLBalanced(pos) ((-2 < balFac(pos)) && (balFac(pos) < 2))

//外部节点也视作黑节点
#define isBlack(pos) (!(pos) || (RB_BLACK == (pos)->color))
//非黑即红
#define isRed(pos) (!isBlack(pos))
/*RedBlack高度更新条件*/
#define blackHeightUpdated(pos)                         \
  ((stature((pos)->l_child) == stature((pos)->r_child)) \
   && ((pos)->height                                    \
       == (isRed(pos) ? stature((pos)->l_child)         \
                      : stature((pos)->l_child) + 1)))

// clang-format on
// define end

template<typename T>
struct BinNode {
  using self = BinNode<T>;
  using value_type = T;
  using size_type = int;
  using iterator = BinNodePosi(T);
  using const_iterator = const BinNodePosi(T);

  value_type data;   //数值
  iterator parent;   // 父节点
  iterator l_child;  // 左孩子
  iterator r_child;  // 右孩子
  size_type height;  //高度（通用）
  size_type npl;  //Null Path Length（左式堆，也可直接用height代替）
  RBColor color;  //颜色（红黑树）

  BinNode()
      : data(),
        parent(nullptr),
        l_child(nullptr),
        r_child(nullptr),
        height(0),
        npl(1),
        color(RBColor::RB_RED) {}

  BinNode(value_type value, iterator p = nullptr, iterator lc = nullptr,
          iterator rc = nullptr, size_type h = 0, size_type l = 1,
          RBColor c = RBColor::RB_RED)
      : data(value),
        parent(p),
        l_child(lc),
        r_child(rc),
        height(h),
        npl(l),
        color(c) {
    if(l_child)
      l_child->parent = this;
    if(r_child)
      r_child->parent = this;
  }

  virtual ~BinNode() = default;

  const_iterator selfNode() const { return this; }

  // 统计当前结点后代总数
  size_type size() const {
    size_type cnt = 1;
    if(l_child)
      cnt += l_child->size();
    if(r_child)
      cnt += r_child->size();
    return cnt;
  }

  //更新当前节点高度
  size_type updateHeight() {
    return height = 1 + std::max(stature(l_child), stature(l_child));
  }

  //更新当前节点及其祖先的高度
  void updateHeightAbove() {
    for(iterator x = this; x; x = x->parent)
      x->updateHeight();
  }

  //将value作为当前节点的左孩子插入二叉树
  iterator insertLC(const T& value) {
    return l_child = new BinNode<T>(value, this);
  }

  //将value作为当前节点的右孩子插入二叉树
  iterator insertRC(const T& value) {
    return r_child = new BinNode<T>(value, this);
  }

  //接入左子树
  void attachLC(iterator pos) {
    l_child = pos;
    if(pos)
      pos->parent = this;
  }

  //接入右子树
  void attachRC(iterator pos) {
    r_child = pos;
    if(pos)
      pos->parent = this;
  }

  //定位当前节点的直接后继
  iterator next() {
    iterator s = this;  //记录后继的临时变量
    if(r_child) {  //若有右孩子，则直接后继必在右子树中，具体地就是
      s = r_child;  //右子树中
      while(s->l_child)
        s = s->l_child;  //最靠左（最小）的节点
    } else {  //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
      while((s->parent) && (s == s->parent->r_child))
        s = s->parent;  //逆向地沿右向分支，不断朝左上方移动
      s = s->parent;  //最后再朝右上方移动一步，即抵达直接后继（如果存在）
    }
    return s;
  }

  // 子树层次遍历
  template<typename Fn>
  void travLevel(Fn&& fn) {
    std::queue<iterator> que;
    que.push(this);
    while(!que.empty()) {
      iterator it = que.front();
      fn(it->data);
      if(hasLChild(it))
        que.push(it->l_child);
      if(hasRChild(it))
        que.push(it->r_child);
      que.pop();
    }
  }

  // 子树先序遍历
  template<typename Fn>
  void travPrev(Fn&& fn) {
    travPrevR(this, std::forward<Fn>(fn));
  }

  // 子树中序遍历
  template<typename Fn>
  void travIn(Fn&& fn) {
    travInR(this, std::forward<Fn>(fn));
  }

  // 子树后序遍历
  template<typename Fn>
  void travPost(Fn&& fn) {
    travPostR(this, std::forward<Fn>(fn));
  }

  //顺时针旋转
  iterator zig() {
    iterator it = l_child;
    if(!it)
      return this;
    it->parent = parent;
    if(it->parent)
      ((this == it->parent->r_child) ? it->parent->r_child
                                     : it->parent->l_child) = it;
    l_child = it->r_child;
    if(l_child)
      l_child->parent = this;
    it->r_child = this;
    parent = it;
    updateHeight();
    it->updateHeight();
    return it;
  }

  //逆时针旋转
  iterator zag() {
    iterator it = r_child;
    if(!it)
      return this;
    it->parent = parent;
    if(it->parent)
      ((this == it->parent->l_child) ? it->parent->l_child
                                     : it->parent->r_child) = it;
    r_child = it->l_child;
    if(r_child)
      r_child->parent = this;
    it->l_child = this;
    parent = it;
    updateHeight();
    it->updateHeight();
    return it;
  }

  //完全平衡化
  iterator balance() {}

  //临摹
  iterator imitate(const_iterator pos) {}
};

template<typename T>
bool
operator<(const BinNode<T>& x, const BinNode<T>& y) {
  return x.data < y.data;
}

template<typename T>
bool
operator==(const BinNode<T>& x, const BinNode<T>& y) {
  return x.data == y.data;
}

//通过zig旋转调整，将BST子树x拉伸成最右侧通路
template<typename T>
void
stretchByZig(iterator<T>& pos) {
  if(!pos)
    return;
  // /*DSA*/ printf("pos->data = %d\n", pos->data);
  /*DSA*/ int cnt = 0;  //记录旋转次数
  iterator<T> r = pos;
  iterator<T> v = pos;
  //最小节点，必是子树最终的根
  for(; r->l_child; r = r->l_child)
    ;
  //从最右侧通路的末端出发
  for(; v->r_child; v = v->r_child)
    ;
  while(v != r) {
    //以v为轴做zig旋转（同时更新高度）
    if(v == v->zig())
      (v = v->parent)->updateHeight();  //直至没有左孩子
    else
      /*DSA*/ ++cnt;
  }
  v->updateHeightAbove();
  /*DSA*/ printf("size = %d, height = %d, #zig = %d\n", r->size(), r->height,
                 cnt);
  pos = r;
}

//通过zag旋转调整，将BST子树x拉伸成最左侧通路
template<typename T>
void
stretchByZag(iterator<T>& pos) {
  if(!pos)
    return;
  // /*DSA*/ printf("pos->data = %d\n", pos->data);
  /*DSA*/ int cnt = 0;  //记录旋转次数
  iterator<T> r = pos;
  iterator<T> v = pos;
  //最大节点，必是子树最终的根
  for(; r->r_child; r = r->r_child)
    ;
  //从最左侧通路的末端出发
  for(; v->l_child; v = v->l_child)
    ;
  while(v != r) {
    //以v为轴做zag旋转（同时更新高度）
    if(v == v->zag())
      (v = v->parent)->updateHeight();  //直至没有右孩子
    else
      /*DSA*/ ++cnt;
  }
  v->updateHeightAbove();
  /*DSA*/ printf("size = %d, height = %d, #zag = %d\n", r->size(), r->height,
                 cnt);
  pos = r;
}

#endif  // BIN_NODE_HPP