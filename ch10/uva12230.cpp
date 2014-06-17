// UVa12230 Crossing Rivers
// Rujia Liu
#include<cstdio>
int main() {
  int n, D, p, L, v, kase = 0;
  while(scanf("%d%d", &n, &D) == 2 && D) {
    double ans = 0;
    while(n--) {
      scanf("%d%d%d", &p, &L, &v);
      D -= L; ans += 2.0 * L / v;
    }
    printf("Case %d: %.3lf\n\n", ++kase, ans + D);
  }
  return 0;
}
