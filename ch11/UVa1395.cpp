// UVa1395 Slim Span
// Rujia Liu
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
const int INF = 1000000000;
int n;

int pa[maxn];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; } 

struct Edge {
  int u, v, d;
  Edge(int u, int v, int d):u(u),v(v),d(d) {}
  bool operator < (const Edge& rhs) const {
    return d < rhs.d;
  }
};

vector<Edge> e;

int solve() {
  int m = e.size();
  sort(e.begin(), e.end());
  int ans = INF;
  for(int L = 0; L < m; L++) {
    for(int i = 1; i <= n; i++) pa[i] = i;
    int cnt = n; // number of sets
    for(int R = L; R < m; R++) {
      int u = findset(e[R].u), v = findset(e[R].v);
      if(u != v) {
        pa[u] = v;
        if(--cnt == 1) { ans = min(ans, e[R].d-e[L].d); break; }
      }
    }
  }
  if(ans == INF) ans = -1;
  return ans;
}

int main() {
  int m, u, v, d;
  while(scanf("%d%d", &n, &m) == 2 && n) {
    e.clear();
    for(int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &d);
      e.push_back(Edge(u, v, d));
    }
    printf("%d\n", solve());
  }
  return 0;
}
