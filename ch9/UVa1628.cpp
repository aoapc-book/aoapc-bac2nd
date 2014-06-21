// UVa1628 Pizza Delivery
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;

int kase, n;
int p[maxn], v[maxn];
int d[maxn][maxn][maxn][2];
int vis[maxn][maxn][maxn][2];

// already considered s~e, still need to delivery to cnt people. 
// pos = 0 means at s, pos = 1 means at e
int dp(int s, int e, int cnt, int pos) {
  if(cnt == 0) return 0;

  int &ans = d[s][e][cnt][pos];
  if(vis[s][e][cnt][pos] == kase) return ans;
  vis[s][e][cnt][pos] = kase;

  ans = 0;  
  if(!pos) {
    for(int i = 0; i < s; i++)
      ans = max(ans, v[i] - cnt * abs(p[i] - p[s]) + dp(i, e, cnt - 1, 0));
    for(int i = e + 1; i < n; i++)
      ans = max(ans, v[i] - cnt * abs(p[i] - p[s]) + dp(s, i, cnt - 1, 1));
  }
  else {
    for(int i = 0; i < s; i++)
      ans = max(ans, v[i] - cnt * abs(p[i] - p[e]) + dp(i, e, cnt - 1, 0));
    for(int i = e + 1; i < n; i++)
      ans = max(ans, v[i] - cnt * abs(p[i] - p[e]) + dp(s, i, cnt - 1, 1));
  }
  return ans;
}

int main() {
  int T;
  scanf("%d",&T);
  memset(vis, 0, sizeof(vis));
  for(kase = 1; kase <= T; kase++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    int ans = 0;
    for(int k = 1; k <= n; k++)
      for(int i = 0; i < n; i++)
        ans = max(ans, v[i] - k * abs(p[i]) + dp(i, i, k - 1, 0));
    printf("%d\n",ans);
  }
  return 0;
}
