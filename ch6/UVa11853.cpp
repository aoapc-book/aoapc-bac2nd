// UVa11853 Paintball
// Rujia Liu

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;
const double W = 1000.0;

int n, vis[maxn];
double x[maxn], y[maxn], r[maxn], left, right;
bool ok;

bool intersect(int c1, int c2) {
  return sqrt((x[c1]-x[c2])*(x[c1]-x[c2]) + (y[c1]-y[c2])*(y[c1]-y[c2])) < r[c1] + r[c2];
}

void check_circle(int u) {
  if(x[u] - r[u] < 0)
    left = min(left, y[u] - sqrt(r[u]*r[u] - x[u]*x[u]));
  if(x[u] + r[u] > W)
    right = min(right, y[u] - sqrt(r[u]*r[u] - (W-x[u])*(W-x[u])));
}

// 能达到底部则返回true
bool dfs(int u) {
  if(vis[u]) return false;
  vis[u] = 1;
  if(y[u] - r[u] < 0) return true;
  for(int v = 0; v < n; v++)
    if(intersect(u, v) && dfs(v)) return true;
  check_circle(u);
  return false;
}

int main() {
  while(scanf("%d", &n) == 1) {
    ok = true;
    left = right = W;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
      scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
    for(int i = 0; i < n; i++)
      if(y[i] + r[i] >= W && dfs(i)) { ok = false; break; } // 从上往下dfs
    if(ok) printf("0.00 %.2lf %.2lf %.2lf\n", left, W, right);
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}
