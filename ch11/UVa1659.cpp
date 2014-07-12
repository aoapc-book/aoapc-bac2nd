// UVa1659 Help Little Laura
// Rujia Liu
// 算法一：改造网络，去掉负权
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

const int maxn = 100 + 10;
const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow;
  double cost;
  Edge(int u, int v, int c, int f, double w):from(u),to(v),cap(c),flow(f),cost(w) {}
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];         // 是否在队列中
  double d[maxn];        // Bellman-Ford
  int p[maxn];           // 上一条弧
  int a[maxn];           // 可改进量

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap, double cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BellmanFord(int s, int t, int& flow, double& cost) {
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
  int MincostMaxflow(int s, int t, double& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s, t, flow, cost));
    return flow;
  }

};

MCMF g;

int x[maxn], y[maxn], c1[maxn], c2[maxn];
vector<int> G[maxn];

int main() {
  int n, a, b, v, kase = 0;
  while(scanf("%d%d%d", &n, &a, &b) == 3) {
    g.init(n+2);
    for(int u = 0; u < n; u++) {
      scanf("%d%d", &x[u], &y[u]);
      G[u].clear();
      for(;;) {
        scanf("%d", &v);
        if(v == 0) break;
        G[u].push_back(v-1);
      }
    }

    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    double sum = 0;
    for(int u = 0; u < n; u++) {
      for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        double d = sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v]));
        double edge_cost = -d*a+b; // minimize sum{edge_cost}
        if(edge_cost >= 0) {
          g.AddEdge(u, v, 1, edge_cost);
        } else {
          g.AddEdge(v, u, 1, -edge_cost);
          c1[v]++; c2[u]++;
          sum += -edge_cost;
        }
      }
    }
    for(int u = 0; u < n; u++) {
      if(c1[u] > c2[u]) g.AddEdge(n, u, c1[u]-c2[u], 0);
      if(c2[u] > c1[u]) g.AddEdge(u, n+1, c2[u]-c1[u], 0);
    }

    double cost;
    int flow = g.MincostMaxflow(n, n+1, cost);
    double ans = sum - cost;
    if(ans < 0) ans = 0; // avoid -0.0
    printf("Case %d: %.2lf\n", ++kase, ans);
  }
  return 0;
}
