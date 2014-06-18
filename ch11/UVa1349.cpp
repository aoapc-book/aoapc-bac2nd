// UVa1349 Optimal Bus Route Design
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

const int maxn = 200 + 10;
const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];         // 是否在队列中
  int d[maxn];           // Bellman-Ford
  int p[maxn];           // 上一条弧
  int a[maxn];           // 可改进量

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BellmanFord(int s, int t, int& flow, int& cost) {
    for(int i = 0; i < n; i++) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = 0;
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
        }
      }
    }
    if(d[t] == INF) return false;
    flow += a[t];
    cost += d[t] * a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    return true;
  }

  // 需要保证初始网络中没有负权圈
  int MincostMaxflow(int s, int t, int& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s, t, flow, cost));
    return flow;
  }

};

MCMF g;

int main() {
  int n, m, d, k;
  while(scanf("%d", &n) == 1 && n) {
    g.init(n*2+2);
    for(int u = 1; u <= n; u++) {
      g.AddEdge(0, u, 1, 0);
      g.AddEdge(n+u, n*2+1, 1, 0);
    }
    for(int i = 1; i <= n; i++) {
      for(;;) {
        int j;
        scanf("%d", &j); if(j == 0) break;
        scanf("%d", &d);
        g.AddEdge(i, j+n, 1, d);
      }
    }

    int cost;
    int flow = g.MincostMaxflow(0, n*2+1, cost);
    if(flow < n) printf("N\n");
    else printf("%d\n", cost);
  }
  return 0;
}
