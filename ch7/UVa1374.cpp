// UVa1374 Power Calculus
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxans = 13; // we got it by experimenting

int n, a[maxans+1];

bool dfs(int d, int maxd) {
  if(a[d] == n) return true;
  if(d == maxd) return false;

  int maxv = a[0];
  for(int i = 1; i <= d; i++) maxv = max(maxv, a[i]);
  if((maxv << (maxd-d)) < n) return false;

  // Always use the last value.
  // I can't prove it, but we haven't found a counter-example for n <= 1000
  for(int i = d; i >= 0; i--) {
    a[d+1] = a[d] + a[i];
    if(dfs(d+1, maxd)) return true;
    a[d+1] = a[d] - a[i];
    if(dfs(d+1, maxd)) return true;
  }
  return false;
}

int solve(int n) {
  if(n == 1) return 0;
  a[0] = 1;
  for(int maxd = 1; maxd < maxans; maxd++) {
    if(dfs(0, maxd)) return maxd;
  }
  return maxans;
}

int main() {
  while(scanf("%d", &n) == 1 && n) {
    printf("%d\n", solve(n));
  }
  return 0;
}
