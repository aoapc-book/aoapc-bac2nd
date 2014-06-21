// UVa1151 Buy or Build
// Rujia Liu
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
const int maxq = 8;
int n;
int x[maxn], y[maxn], cost[maxq];
vector<int> subn[maxq];

int pa[maxn];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; } 

struct Edge {
  int u, v, d;
  Edge(int u, int v, int d):u(u),v(v),d(d) {}
  bool operator < (const Edge& rhs) const {
    return d < rhs.d;
  }
};

// initialize pa and sort e before calling this method
// cnt is the current number of components
int MST(int cnt, const vector<Edge>& e, vector<Edge>& used) {
  if(cnt == 1) return 0;
  int m = e.size();
  int ans = 0;
  used.clear();
  for(int i = 0; i < m; i++) {
    int u = findset(e[i].u), v = findset(e[i].v);
    int d = e[i].d;
    if(u != v) {
      pa[u] = v;
      ans += d;
      used.push_back(e[i]);
      if(--cnt == 1) break;
    }
  }
  return ans;
}

int main() {
  int T, q;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &q);
    for(int i = 0; i < q; i++) {
      int cnt;
      scanf("%d%d", &cnt, &cost[i]);
      subn[i].clear();
      while(cnt--) {
        int u;
        scanf("%d", &u);
        subn[i].push_back(u-1);
      }
    }
    for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

    vector<Edge> e, need;
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++) {
        int c = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
        e.push_back(Edge(i, j, c));
      }

    for(int i = 0; i < n; i++) pa[i] = i;
    sort(e.begin(), e.end());

    int ans = MST(n, e, need);
    for(int mask = 0; mask < (1<<q); mask++) {
      // union cities in the same sub-network
      for(int i = 0; i < n; i++) pa[i] = i;
      int cnt = n, c = 0;
      for(int i = 0; i < q; i++) if(mask & (1<<i)) {
        c += cost[i];
        for(int j = 1; j < subn[i].size(); j++) {
          int u = findset(subn[i][j]), v = findset(subn[i][0]);
          if(u != v) { pa[u] = v; cnt--; }
        }
      }
      vector<Edge> dummy;
      ans = min(ans, c + MST(cnt, need, dummy));
    }
    printf("%d\n", ans);
    if(T) printf("\n");
  }
  return 0;
}
