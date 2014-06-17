// UVa10213 How Many Pieces of Land?
// Rujia Liu
#include<cstdio>
int main() {
  int n, T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    int V = 0, E = 0;
    for(int i = 0; i <= n-2; i++)
      V += i*(n-2-i), E += i*(n-2-i)+1;
    V = V*n/4+n;
    E = E*n/2+n;
    printf("%d\n", E-V+1);
  }
  return 0;
}
