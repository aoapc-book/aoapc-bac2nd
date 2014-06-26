// UVa1336 Fixing the Great Wall
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cassert>
using namespace std;

const int maxn = 1000 + 5;
const double INF = 1e30;

struct Section {
  double x, c, dt;
  bool operator < (const Section& rhs) const {
    return x < rhs.x;
  }
} s[maxn];

int kase, n;
int vis[maxn][maxn][2];
double v, x, d[maxn][maxn][2];
double psdt[maxn]; // prefix sum of dt

// cost accumulated when walking from x1 and x2.
// section[i~j] are already finished
double cost(double x1, double x2, int i, int j) {
  double finished_dt = 0;
  assert(i <= j);
  if(i >= 0 && j >= 0) finished_dt += psdt[j] - psdt[i-1];
  return (psdt[n] - finished_dt) * fabs(x2 - x1) / v;
}

double dp(int i, int j, int p) {
  if(i == 1 && j == n) return 0;
  double& ans = d[i][j][p];
  if(vis[i][j][p] == kase) return ans;
  vis[i][j][p] = kase;

  ans = INF;
  double x = (p == 0 ? s[i].x : s[j].x);
  if(i > 1) ans = min(ans, dp(i-1, j, 0) + cost(x, s[i-1].x, i, j));
  if(j < n) ans = min(ans, dp(i, j+1, 1) + cost(x, s[j+1].x, i, j));
  return ans;
}

int main() {
  memset(vis, 0, sizeof(vis));
  while(scanf("%d%lf%lf", &n, &v, &x) == 3 && n) {
    ++kase;
    double sumc = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%lf%lf%lf", &s[i].x, &s[i].c, &s[i].dt);
      sumc += s[i].c;
    }
    sort(s+1, s+n+1); // in increasing order of position

    psdt[0] = 0;
    for(int i = 1; i <= n; i++)
      psdt[i] = psdt[i-1] + s[i].dt;

    s[0].x = -INF;
    s[n+1].x = INF;
    double ans = INF;
    for(int i = 1; i <= n+1; i++)
      if(x > s[i-1].x && x < s[i].x) {
        if(i > 1) ans = min(ans, dp(i-1, i-1, 0) + cost(x, s[i-1].x, -1, -1)); // move left
        if(i <= n) ans = min(ans, dp(i, i, 0) + cost(x, s[i].x, -1, -1)); // move right
        break;
      }
    printf("%.0lf\n", floor(ans + sumc));
  }
  return 0;
}
