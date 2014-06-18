// UVa11082 Matrix Decompressing
// Rujia Liu
// Slower version with EdmondsKarp
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 50 + 5;
const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f):from(u),to(v),cap(c),flow(f) {}
};

struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;    // 边数的两倍
  vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  int a[maxn];           // 当起点到i的可改进量
  int p[maxn];           // 最短路树上p的入弧编号

  void init(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for(;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if(!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap-e.flow);
            Q.push(e.to);
          }
        }
        if(a[t]) break;
      }
      if(!a[t]) break;
      for(int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

EdmondsKarp g;
int no[maxn][maxn];

int main() {
  int T, R, C, v, kase = 0;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; kase++) {
    scanf("%d%d", &R, &C);
    g.init(R+C+2);
    int last = 0;
    for(int i = 1; i <= R; i++) {
      scanf("%d", &v);
      g.AddEdge(0, i, v - last - C); // row sum is v - last
      last = v;
    }
    last = 0;
    for(int i = 1; i <= C; i++) {
      scanf("%d", &v);
      g.AddEdge(R+i, R+C+1, v - last - R); // col sum is v - last
      last = v;
    }
    for(int i = 1; i <= R; i++)
      for(int j = 1; j <= C; j++) {
        g.AddEdge(i, R+j, 19);
        no[i][j] = g.edges.size() - 2; // no[i][j] is the index of arc for cell(i,j)
      }
    g.Maxflow(0, R+C+1);

    printf("Matrix %d\n", kase);
    for(int i = 1; i <= R; i++) {
      for(int j = 1; j <= C; j++)
        printf("%d ", g.edges[no[i][j]].flow + 1); // we subtracted 1 from every cell
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
