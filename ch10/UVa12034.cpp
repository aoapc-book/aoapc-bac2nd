// UVa12034 Race
// Rujia Liu
#include<cstdio>

const int maxn = 1000;
const int MOD = 10056;
int C[maxn+1][maxn+1], f[maxn+1];

// 递推出所有组合数
void init() {
  for(int i = 0; i <= maxn; i++) {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
  }
}

int main() {
  init();
  f[0] = 1;
  for(int i = 1; i <= maxn; i++) {
    f[i] = 0;
    for(int j = 1; j <= i; j++) f[i] = (f[i] + C[i][j] * f[i-j]) % MOD;
  }

  int T, n;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; kase++) {
    scanf("%d", &n);
    printf("Case %d: %d\n", kase, f[n]);
  }
  return 0;
}
