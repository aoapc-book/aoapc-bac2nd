// UVa10491 Cows and Cars
// Rujia Liu
#include<cstdio>
int main() {
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c) == 3)
    printf("%.5lf\n", (double)(a*b+b*(b-1)) / (a+b) / (a+b-c-1));
  return 0;
}
