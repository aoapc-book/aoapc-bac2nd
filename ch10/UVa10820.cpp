// UVa10820 Send a Table
// Rujia Liu
#include<cstdio>
#include<cmath>
const int maxn = 50000;
int phi[maxn+1], phi_psum[maxn+1];

void phi_table(int n) {
  phi[1] = 0;
  for(int i = 2; i <= n; i++) if(phi[i] == 0)
  for(int j = i; j <= n; j += i) {
    if(phi[j] == 0) phi[j] = j;
    phi[j] = phi[j] / i * (i-1);
  }
}

int main(){
  int n;
  phi_table(maxn);
  phi_psum[0] = 0;
  for(int i = 1; i <= maxn; i++)
    phi_psum[i] = phi_psum[i-1] + phi[i];
  while(scanf("%d", &n) == 1 && n)
    printf("%d\n",2*phi_psum[n] + 1);
  return 0;
}
