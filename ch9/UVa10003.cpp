// UVa10003 Cutting Sticks
// Rujia Liu
// 算法：设d[i][j]为切割小木棍i~j的最优费用，则d[i][j]=min{d[i][k]+d[k][j]}+a[j]-a[i]。最后的a[j]-a[i]是第一刀的费用。然后分成i~k和k~j两部分。
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 50 + 5;
int n, L, a[maxn], vis[maxn][maxn], d[maxn][maxn];

int dp(int i, int j) {
  if(i >= j - 1) return 0;
  if(vis[i][j]) return d[i][j];
  vis[i][j] = 1;
  int& ans = d[i][j];
  ans = -1;
  for(int k = i+1; k <= j-1; k++) {
    int v = dp(i,k) + dp(k,j) + a[j] - a[i];
    if(ans < 0 || v < ans) ans = v;
  }
  return ans;
}

int main() {
  while(scanf("%d%d", &L, &n) == 2 && L) {
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = 0; a[n+1] = L;
    memset(vis, 0, sizeof(vis));
    printf("The minimum cutting is %d.\n", dp(0, n+1));
  }
  return 0;
}
