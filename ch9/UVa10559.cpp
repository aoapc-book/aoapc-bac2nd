// UVa10559 Blocks
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 200 + 5;
int n, A[maxn], d[maxn][maxn][maxn];

// blocks i~j, plus k blocks whose color is the same as block j
int dp(int i, int j, int k) {
  if(i > j) return 0;
  int& ans = d[i][j][k];
  if(ans >= 0) return ans;
  int p = j;
  while(p >= i && A[p] == A[j]) p--;
  p++; // leftmost position that block j's color can "extend" to
  ans = dp(i, p-1, 0) + (j-p+k+1)*(j-p+k+1); // click block j
  for(int q = i; q < p; q++)
    if(A[q] == A[j] && A[q] != A[q+1]) // remove q+1~p-1 first
      ans = max(ans, dp(q+1, p-1, 0) + dp(i, q, j-p+k+1));
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; kase++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    memset(d, -1, sizeof(d));
    printf("Case %d: %d\n", kase, dp(0, n-1, 0));
  }
  return 0;
}
