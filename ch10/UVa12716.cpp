// UVa12716 GCD XOR
// Rujia Liu

#include<cstdio>
#include<cstring>
using namespace std;

const int M = 30000000;
int cnt[M+1], sum[M+1];

void init() {
  memset(cnt, 0, sizeof(cnt));
  for(int c = 1; c <= M; c++)
    for(int a = c*2; a <= M; a += c) {
      int b = a - c;
      if(c == (a ^ b)) cnt[a]++;
    }
  sum[0] = 0;
  for(int i = 1; i <= M; i++) sum[i] = sum[i-1] + cnt[i];
}

int main() {
  init();
  int T, n, kase = 0;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    printf("Case %d: %d\n", ++kase, sum[n]);
  }
  return 0;
}
