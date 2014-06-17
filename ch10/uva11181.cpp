// UVa11181 Probability|Given
// Rujia Liu
#include<cstdio>
#include<cstring>
const int maxn = 20 + 5;
int n, r, buy[maxn];
double P[maxn], sum[maxn];

// depth, current number of 1, and product of probs
void dfs(int d, int c, double prob) {
  if(c > r || d - c > n - r) return; // too many 1/0
  if(d == n) {
    sum[n] += prob;
    for(int i = 0; i < n; i++) if(buy[i])
      sum[i] += prob;
    return;
  }
  buy[d] = 0;
  dfs(d+1, c, prob*(1-P[d]));
  buy[d] = 1;
  dfs(d+1, c+1, prob*P[d]);
}

int main() {
  int kase = 0;
  while(scanf("%d%d", &n, &r) == 2 && n) {
    for(int i = 0; i < n; i++) scanf("%lf", &P[i]);
    memset(sum, 0, sizeof(sum));
    dfs(0, 0, 1.0);
    printf("Case %d:\n", ++kase);
    for(int i = 0; i < n; i++)
      printf("%.6lf\n", sum[i] / sum[n]);
  }
  return 0;
}
