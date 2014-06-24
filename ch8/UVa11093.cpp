// UVa11093 Just Finish it up
// Rujia Liu
#include<cstdio>

const int maxn = 100000 + 5;
int n, p[maxn], q[maxn];

// returns s if success
// otherwise, return the station you failed to reach
// if you failed to reach the start, return -1
int go(int s) {
  int fuel = p[s] - q[s];
  for(int i = (s+1)%n; i != s; i = (i+1)%n) {
    if(fuel < 0) return i;
    fuel += p[i] - q[i];
  }
  if(fuel < 0) return -1; // this means sum(p) < sum(q), so this case is impossible
  return s; // success
}

int solve() {
  int start = 0;
  for(;;) {
    int finish = go(start);
    if(finish < start) return -1; // wrapped around, or go(start) returns -1
    if(finish == start) return start;
    start = finish;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; kase++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    int ans = solve();
    printf("Case %d: ", kase);
    if(ans < 0) printf("Not possible\n");
    else printf("Possible from station %d\n", ans+1);
  }
  return 0;
}
