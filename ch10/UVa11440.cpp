// UVa11440 Help Mr. Tomisu
// Rujia Liu
#include<cstdio>
#include<cmath>
#include<cstring>
const int maxn = 10000000 + 10;
const int MOD = 100000007;

int vis[maxn], phifac[maxn];

void gen_primes(int n) {
  int m = (int)sqrt(n+0.5);
  int c = 0;
  memset(vis, 0, sizeof(vis));
  for(int i = 2; i <= m; i++) if(!vis[i]) {
    for(int j = i*i; j <= n; j+=i) vis[j] = 1;
  }
}

int main() {
  int n, m;
  gen_primes(10000000);
  phifac[1] = phifac[2] = 1;
  for(int i = 3; i <= 10000000; i++)
    phifac[i] = (long long)phifac[i-1] * (vis[i] ? i : i-1) % MOD;

  while(scanf("%d%d", &n, &m) == 2 && n) {
    int ans = phifac[m];
    for(int i = m+1; i <= n; i++) ans = (long long)ans * i % MOD;
    printf("%d\n", (ans-1+MOD)%MOD);
  }
  return 0;
}
