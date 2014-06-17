// UVa11346 Probability
// Rujia Liu
#include<cstdio>
#include<cmath>
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    double a, b, s, ans;
    scanf("%lf%lf%lf", &a, &b, &s);
    double m = a*b;
    if(fabs(s) < 1e-6) ans = 1;
    else if(s > m) ans = 0;
    else ans = (m - s - s * log(m/s)) / m;
    printf("%.6lf%%\n", ans * 100);
  }
  return 0;
}
