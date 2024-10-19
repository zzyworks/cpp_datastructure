#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <climits>
#include <queue>
#include <utility>

// 顶点状态
enum class VStatus : unsigned int { UNDISCOVERED, DISCOVERED, VISITED };

// 边在遍历树中所属的类型
enum class EType : unsigned int {
  UNDETERMINED,
  TREE,
  CROSS,
  FORWARD,
  BACKWARD
};

// VT = vertex type, ET = edge type
template<class VT, class ET>
class Graph {
public:
  using size_type = int;
  using vertex_type = VT;
  using edge_type = ET;
  using value_type_v = VT;
  using value_type_e = ET;
  using reference_v = VT&;
  using const_reference_v = const VT&;
  using reference_e = ET&;
  using const_reference_e = const ET&;
  using pointer_v = VT*;
  using const_pointer_v = const VT*;
  using pointer_e = ET*;
  using const_pointer_e = const ET*;

private:
  // 所有顶点、边的辅助信息复位
  void reset() {
    for(size_type i = 0; i < vertex_n; i++) {
      status(i) = VStatus::UNDISCOVERED;
      dTime(i) = fTime(i) = -1;  //状态，时间标签
      parent(i) = -1;
      //（在遍历树中的）父节点，优先级数
      priority(i) = INT_MAX;
      //所有边的
      for(int j = 0; j < vertex_n; j++) {
        if(exists(i, j))
          //类型
          type(i, j) = EType::UNDETERMINED;
      }
    }
  }

  // 广度优先搜索BFS算法 assert: 0 <= v < n
  // void BFS(size_type pos, size_type& clock) {
  //   std::queue<size_type> que;
  //   status(pos) = VStatus::DISCOVERED;
  //   que.push(pos);
  //   while(!que.empty()) {
  //     pos = que.front();
  //     que.pop();
  //     dTime(pos) = ++clock;
  //     for(size_type k = 0, u = firstNeighbor(pos); k != outDegree(pos);
  //         ++k, u = nextNeighbor(pos, u)) {
  //       if(VStatus::UNDISCOVERED == status(pos)) {
  //         status(u) = VStatus::DISCOVERED;
  //         que.push(u);
  //         type(pos, u) = EType::TREE;
  //         parent(u) = pos;
  //       } else {
  //         type(pos, u) = EType::CROSS;
  //       }
  //     }
  //     status(pos) = VStatus::VISITED;
  //   }
  // }

  //广度优先搜索BFS算法（单个连通域）
  void BFS(size_type pos, size_type& clock) {
    //assert: 0 <= pos < vertex_n
    std::queue<int> Q;
    status(pos) = VStatus::DISCOVERED;
    Q.push(pos);
    while(!Q.empty()) {
      size_type v = Q.front();
      Q.pop();
      dTime(v) = ++clock;
      //枚举v的所有邻居u
      for(size_type u = firstNeighbor(v); u != -1; u = nextNeighbor(v, u)) {
        if(VStatus::UNDISCOVERED == status(u)) {
          status(u) = VStatus::DISCOVERED;
          Q.push(u);
          type(v, u) = EType::TREE;
          //引入树边拓展支撑树
          parent(u) = v;
        } else
          //将(v, u)归类于跨边
          type(v, u) = EType::CROSS;
      }
      //至此，当前顶点访问完毕
      status(v) = VStatus::VISITED;
    }
  }

  // // （连通域）深度优先搜索算法
  // void DFS(int, int&);

  // // （连通域）基于DFS的双连通分量分解算法
  // void BCC(int, int&, Stack<int>&);

  // // （连通域）基于DFS的拓扑排序算法
  // bool TSort(int, int&, Stack<VT>*);

  // // （连通域）优先级搜索框架
  // template<typename PU>
  // void PFS(int, PU) {}

public:
  size_type vertex_n;  // 顶点总数
  size_type edge_n;    // 边总数

  // 顶点

  virtual reference_v vertex(size_type) = 0;
  virtual size_type inDegree(size_type) = 0;
  virtual size_type outDegree(size_type) = 0;
  virtual int firstNeighbor(int) = 0;
  virtual int nextNeighbor(int, int) = 0;
  virtual VStatus& status(size_type) = 0;
  virtual size_type& dTime(size_type) = 0;
  virtual size_type& fTime(size_type) = 0;
  virtual size_type& parent(size_type) = 0;
  virtual size_type& priority(size_type) = 0;
  virtual void pushVertex(const VT&) = 0;
  virtual void eraseVertex(size_type) = 0;

  // 边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例

  virtual bool exists(size_type, size_type) = 0;
  virtual EType& type(size_type, size_type) = 0;
  virtual reference_e edge(size_type, size_type) = 0;
  virtual size_type& weight(size_type, size_type) = 0;
  virtual void pushEdge(size_type, size_type, const ET&, size_type) = 0;
  virtual void eraseEdge(size_type, size_type) = 0;

  // 算法

  //广度优先搜索BFS算法（全图）
  void bfs(size_type pos) {
    //assert: 0 <= pos < vertex_n
    reset();
    size_type clock = 0;
    for(size_type v = pos; v != pos + vertex_n; ++v) {
      if(VStatus::UNDISCOVERED == status(v % vertex_n))
        BFS(v % vertex_n, clock);
    }
  }

  // void dfs(int);          //深度优先搜索算法
  // void bcc(int);          //基于DFS的双连通分量分解算法
  // Stack<VT>* tSort(int);  //基于DFS的拓扑排序算法
  // void prim(int);         //最小支撑树Prim算法
  // void dijkstra(int);     //最短路径Dijkstra算法
  // template<typename PU>
  // void pfs(int, PU);  //优先级搜索框架
};

#endif  // GRAPH_HPP