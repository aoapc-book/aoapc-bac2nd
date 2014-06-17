// UVa437 The Tower of Babylon
// Rujia Liu
// 算法：DAG上的最长路，状态为(idx, k)，即当前顶面为立方体idx，其中第k条边（排序后）为高
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)

const int maxn = 30 + 5;
int n, blocks[maxn][3], d[maxn][3];

void get_dimensions(int* v, int b, int dim) {
  int idx = 0;
  REP(i,3) if(i != dim) v[idx++] = blocks[b][i];
}

int dp(int i, int j) {
  int& ans = d[i][j];
  if(ans > 0) return ans;
  ans = 0;
  int v[2], v2[2];
  get_dimensions(v, i, j);
  REP(a,n) REP(b,3) {
    get_dimensions(v2, a, b);
    if(v2[0] < v[0] && v2[1] < v[1]) ans = max(ans, dp(a,b));
  }
  ans += blocks[i][j];
  return ans;
}

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1 && n) {
    REP(i,n) {
      REP(j,3) scanf("%d", &blocks[i][j]);
      sort(blocks[i], blocks[i]+3);
    }
    memset(d, 0, sizeof(d));
    int ans = 0;
    REP(i,n) REP(j,3) ans = max(ans, dp(i,j));
    printf("Case %d: maximum height = %d\n", ++kase, ans);
  }
  return 0;
}
