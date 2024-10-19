#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP

#include <memory>
#include <vector>

#include "graph.hpp"

// 顶点对象
template<typename VT>
struct Vertex {
  using size_type = int;
  using value_type = VT;

  value_type data;      // 数据
  size_type inDegree;   // 入度
  size_type outDegree;  // 出度
  VStatus status;       // 状态
  size_type dTime;      // 时间标签
  size_type fTime;      // 时间标签
  size_type parent;     // 在遍历树中的父节点
  size_type priority;   // 在遍历树中的优先级数

  Vertex(const VT& v = {})
      : data(v),
        inDegree(0),
        outDegree(0),
        status(VStatus::UNDISCOVERED),
        dTime(-1),
        fTime(-1),
        parent(-1),
        priority(INT_MAX) {}

  // Vertex(const Vertex& other)
  //     : data(other.data),
  //       inDegree(other.inDegree),
  //       outDegree(other.outDegree),
  //       status(other.status),
  //       dTime(other.dTime),
  //       fTime(other.fTime),
  //       parent(other.parent),
  //       priority(other.priority) {}

  // Vertex& operator=(const Vertex& other) {
  //   data = other.data;
  //   inDegree = other.inDegree;
  //   outDegree = other.outDegree;
  //   status = other.status;
  //   dTime = other.dTime;
  //   fTime = other.fTime;
  //   parent = other.parent;
  //   priority = other.priority;
  // }
};

// 边对象
template<typename ET>
struct Edge {
  using size_type = int;
  using value_type = ET;

  value_type data;
  size_type weight;
  EType type;

  Edge(const ET& e, size_type w)
      : data(e), weight(w), type(EType::UNDETERMINED) {}
};

// 基于向量，以邻接矩阵形式实现的图
template<class VT, class ET>
class GraphMatrix : public Graph<VT, ET> {
public:
  using self = GraphMatrix<VT, ET>;
  using base = Graph<VT, ET>;
#define base_t typename base
  using size_type = base_t::size_type;
  using vertex_type = base_t::vertex_type;
  using edge_type = base_t::edge_type;
  using value_type_v = base_t::value_type_v;
  using value_type_e = base_t::value_type_e;
  using reference_v = base_t::reference_v;
  using const_reference_v = base_t::const_reference_v;
  using reference_e = base_t::reference_e;
  using const_reference_e = base_t::const_reference_e;
  using pointer_v = base_t::pointer_v;
  using const_pointer_v = base_t::const_pointer_v;
  using pointer_e = base_t::pointer_e;
  using const_pointer_e = base_t::const_pointer_e;

private:
  size_type vertex_n_ = base::vertex_n;
  size_type edge_n_ = base::edge_n;
  using vertexs_t = std::vector<Vertex<VT>>;
  vertexs_t vertexs_;  //顶点集（向量）
  using edges_t = std::vector<std::vector<std::unique_ptr<Edge<ET>>>>;
  edges_t edges_;  //边集（邻接矩阵）

public:
  GraphMatrix() : vertex_n_(0), edge_n_(0) {}

  ~GraphMatrix() = default;

  // 顶点的基本操作：查询第pos个顶点（0 <= pos < vertex_n_）

  // 数据
  virtual reference_v vertex(size_type pos) override {
    return vertexs_[pos].data;
  }

  // 入度
  virtual size_type inDegree(size_type pos) override {
    return vertexs_[pos].inDegree;
  }

  // 出度
  virtual size_type outDegree(size_type pos) override {
    return vertexs_[pos].outDegree;
  }

  // pos的首个邻接顶点
  virtual int firstNeighbor(int pos) override {
    return nextNeighbor(pos, vertex_n_);
  }

  // 顶点pos1的（相对于顶点pos2的）下一邻接顶点
  virtual int nextNeighbor(int pos1, int pos2) override {
    // 逆向线性试探
    while((-1 != --pos2) && (!exists(pos1, pos2)))
      ;
    return pos2;
  }

  // 顶点的状态
  virtual VStatus& status(size_type pos) override {
    return vertexs_[pos].status;
  }

  // 顶点的时间标签dTime
  virtual size_type& dTime(size_type pos) override {
    return vertexs_[pos].dTime;
  }

  // 顶点的时间标签fTime
  virtual size_type& fTime(size_type pos) override {
    return vertexs_[pos].fTime;
  }

  // 顶点在遍历树中的父亲
  virtual size_type& parent(size_type pos) override {
    return vertexs_[pos].parent;
  }

  // 顶点在遍历树中的优先级数
  virtual size_type& priority(size_type pos) override {
    return vertexs_[pos].priority;
  }

  size_type vertexCount() const {
    return vertex_n_;
  }

  // 顶点的动态操作

  // 插入顶点
  virtual void pushVertex(const VT& v) override {
    // 顶点向量增加一个顶点
    vertexs_.push_back(Vertex<value_type_v>(v));
    // 创建新顶点对应的边向量
    edges_.push_back(std::vector<std::unique_ptr<Edge<value_type_e>>>());
    for(size_type i = 0; i < vertex_n_; i++)
      edges_[vertex_n_].push_back(nullptr);
    ++vertex_n_;
    size_type cnt = 0;
    for(size_type i = 0; i < vertex_n_; i++) {
      edges_[i].push_back(nullptr);
      ++cnt;
      if(edges_[i].size() < vertex_n_) {
        for(size_type j = 0; j != vertex_n_ - cnt; ++j)
          edges_[i].push_back(nullptr);
      }
      cnt = 0;
    }
  }

  // 删除第pos个顶点及其关联边（0 <= pos < vertex_n_）
  virtual void eraseVertex(size_type pos) override {
    removeVertex(pos);
  }

  value_type_v removeVertex(size_type pos) {
    for(size_type i = 0; i != vertex_n_; ++i) {
      eraseEdge(pos, i);
      if(exists(i, pos))
        --vertexs_[i].outDegree;
    }
    --vertex_n_;
    value_type_v vertex = vertexs_[pos].data;
    vertexs_.erase(vertexs_.begin() + pos);
    edges_.erase(edges_.begin() + pos);
    for(size_type i = 0; i != vertex_n_; ++i)
      edges_[i].erase(edges_[i].begin() + pos);
    return vertex;
  }

  // 边的确认操作

  // x-y的边是否存在
  virtual bool exists(size_type pos1, size_type pos2) override {
    return (pos1 < vertex_n_) && (pos2 < vertex_n_) && edges_[pos1][pos2];
  }

  // 边的基本操作：查询顶点x与y之间的联边（0 <= (x, y) < vertex_n_且exists(x, y)）

  // 边(i, j)的类型
  virtual EType& type(size_type pos1, size_type pos2) override {
    return edges_[pos1][pos2]->type;
  }

  // 边(i, j)的数据
  virtual reference_e edge(size_type pos1, size_type pos2) override {
    return edges_[pos1][pos2]->data;
  }

  // 边(i, j)的权重
  virtual size_type& weight(size_type pos1, size_type pos2) override {
    return edges_[pos1][pos2]->weight;
  }

  size_type edgeCount() const {
    return edge_n_;
  }

  // 边的动态操作

  // 插入权重为w的边(e = x->y)
  virtual void pushEdge(size_type pos1, size_type pos2, const ET& e,
                        size_type w) override {
    if(exists(pos1, pos2))
      return;
    edges_[pos1][pos2] = std::make_unique<Edge<value_type_e>>(e, w);
    ++edge_n_;
    ++vertexs_[pos1].outDegree;
    ++vertexs_[pos2].inDegree;
  }

  // 删除顶点x和y之间的联边
  virtual void eraseEdge(size_type pos1, size_type pos2) override {
    removeEdge(pos1, pos2);
  }

  std::unique_ptr<Edge<ET>> removeEdge(size_type pos1, size_type pos2) {
    if(!exists(pos1, pos2))
      return nullptr;
    std::unique_ptr<Edge<ET>> edge =
      std::make_unique<Edge<ET>>(*edges_[pos1][pos2]);
    edges_[pos1][pos2] = nullptr;
    --edge_n_;
    --vertexs_[pos1].outDegree;
    --vertexs_[pos2].inDegree;
    return edge;
  }
};

#endif  // GRAPH_MATRIX_HPP