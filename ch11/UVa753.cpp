// UVa753 A Plug for UNIX
// Rujia Liu
// 算法一：先做一次floyd，然后再构图
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

vector<string> names;
int ID(const string& s) {
  for(int i = 0; i < names.size(); i++)
    if(names[i] == s) return i;
  names.push_back(s);
  return names.size() - 1;
}

const int maxn = 400 + 5; 

int n, m, k;       // 插座个数，设备个数，转换器个数
int d[maxn][maxn]; // d[i][j]=1表示插头类型i可以转化为插头类型j
int target[maxn];  // 各个插座的类型
int device[maxn];  // 各个设备的类型

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

int main() {
  int T;
  cin >> T;
  while(T--) {
    names.clear();
    string s1, s2;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> s1;
      target[i] = ID(s1);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
      cin >> s1 >> s2;
      device[i] = ID(s2);
    }
    cin >> k;
    memset(d, 0, sizeof(d));
    for(int i = 0; i < k; i++) {
      cin >> s1 >> s2;
      d[ID(s1)][ID(s2)] = 1;
    }
    // floyd
    int V = names.size(); // 插头类型个数
    for(int k = 0; k < V; k++)
      for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
          d[i][j] |= d[i][k] && d[k][j];
    
    g.init(V+2);
    for(int i = 0; i < m; i++)
      g.AddEdge(V, device[i], 1); // 源点->设备
    for(int i = 0; i < n; i++)
      g.AddEdge(target[i], V+1, 1); // 插座->汇点

    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        if(d[device[i]][target[j]]) g.AddEdge(device[i], target[j], INF); // 设备->插座
    int r = g.Maxflow(V, V+1);
    cout << m-r << "\n";
    if(T) cout << "\n";
  }
  return 0;
}
