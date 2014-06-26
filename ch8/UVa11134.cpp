// UVa11134 Fabled Rooks
// Rujia Liu
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;

// solve 1-D problem: find c so that a[i] <= c[i] <= b[i] (0 <= i < n)
bool solve(int *a, int *b, int *c, int n) {
  fill(c, c+n, -1);
  for(int col = 1; col <= n; col++) {
    // find a rook with smalleset b that is not yet assigned
    int rook = -1, minb = n+1;
    for(int i = 0; i < n; i++)
      if(c[i] < 0 && b[i] < minb && col >= a[i]) { rook = i; minb = b[i]; }
    if(rook < 0 || col > minb) return false;
    c[rook] = col;
  }
  return true;
}

const int maxn = 5000 + 5;
int n, x1[maxn], y1[maxn], x2[maxn], y2[maxn], x[maxn], y[maxn];

int main() {
  while(scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++)
      scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    if(solve(x1, x2, x, n) && solve(y1, y2, y, n))
      for (int i = 0; i < n; i++) printf("%d %d\n", x[i], y[i]);
    else
      printf("IMPOSSIBLE\n");
  }
  return 0;
}
