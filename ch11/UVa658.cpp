// UVa658 It's not a Bug, it's a Feature!
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Node {
  int bugs, dist;
  bool operator < (const Node& rhs) const {
    return dist > rhs.dist;
  }
};

const int maxn = 20;
const int maxm = 100 + 5;
const int INF = 1000000000;

int n, m, t[maxm], dist[1<<maxn], mark[1<<maxn];
char before[maxm][maxn + 5], after[maxm][maxn + 5];

int solve() {
  for(int i = 0; i < (1<<n); i++) { mark[i] = 0; dist[i] = INF; }
  priority_queue<Node> q;

  Node start;
  start.dist = 0;
  start.bugs = (1<<n) - 1;
  q.push(start);

  dist[start.bugs] = 0;
  while(!q.empty()) {
    Node u = q.top(); q.pop();
    if(u.bugs == 0) return u.dist;
    if(mark[u.bugs]) continue;
    mark[u.bugs] = 1;
    for(int i = 0; i < m; i++) {
      bool patchable = true;
      for(int j = 0; j < n; j++) {
        if(before[i][j] == '-' && (u.bugs & (1<<j))) { patchable = false; break; }
        if(before[i][j] == '+' && !(u.bugs & (1<<j))) { patchable = false; break; }
      }
      if(!patchable) continue;

      Node u2;
      u2.dist = u.dist + t[i];
      u2.bugs = u.bugs;
      for(int j = 0; j < n; j++) {
        if(after[i][j] == '-') u2.bugs &= ~(1<<j);
        if(after[i][j] == '+') u2.bugs |= (1<<j);
      }
      int& D = dist[u2.bugs];
      if(D < 0 || u2.dist < D) {
        D = u2.dist;
        q.push(u2);
      }
    }
  }
  return -1;
}

int main() {
  int kase = 0;
  while(scanf("%d%d", &n, &m) == 2 && n) {
    for(int i = 0; i < m; i++) scanf("%d%s%s", &t[i], before[i], after[i]);
    int ans = solve();
    printf("Product %d\n", ++kase);
    if(ans < 0) printf("Bugs cannot be fixed.\n\n");
    else printf("Fastest sequence takes %d seconds.\n\n", ans);
  }
  return 0;
}
