// UVa1607 Gates
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxm = 200000 + 5;

int n, m;

struct Gates {
  int a, b, o;
} gates[maxm];

// returns the output of input 000..0111...1 (there are k 0's)
int output(int k) {
  for(int i = 1; i <= m; i++) {
    int a = gates[i].a;
    int b = gates[i].b;
    int va = a < 0 ? -a > k : gates[a].o;
    int vb = b < 0 ? -b > k : gates[b].o;
    gates[i].o = !(va && vb);
  }
  return gates[m].o;
}

// returns k such that 
// 1. output(k) = output(n)
// 2. output(k-1) = output(0)
int solve(int vn) {
  int L = 1, R = n;
  while(L < R) {
    int M = L + (R-L)/2;
    if(output(M) == vn) R = M; else L = M+1;
  }
  return L;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
      scanf("%d%d", &gates[i].a, &gates[i].b);
    int v0 = output(0);
    int vn = output(n);
    if(v0 == vn) {
      for(int i = 1; i <= n; i++) printf("0");
    } else {
      int x = solve(vn);
      for(int i = 1; i < x; i++) printf("0");
      printf("x");
      for(int i = x+1; i <= n; i++) printf("1");
    }
    printf("\n");
  }
  return 0;
}
