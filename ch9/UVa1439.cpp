// UVa1439 Exclusive Access 2
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

// This is different from problem statement
// Here n is the number of resources, m is the number of processes (n in the problem statement)
const int maxn = 15;
const int maxm = 100 + 5;
int n, m, u[maxm], v[maxm], G[maxn][maxn];
int ind[1<<maxn], d[1<<maxn], best[1<<maxn], label[maxn];

bool independent(int mask) {
  for(int i = 0; i < maxn; i++) if(mask & (1<<i))
    for(int j = 0; j < maxn; j++) if(mask & (1<<j))
      if(i != j && G[i][j]) return false;
  return true;
}

// How many colors are needed to color the set 'mask'
int dp(int mask) {
  int& ans = d[mask];
  if(ans >= 0) return ans;
  if(mask == 0) return 0;
  ans = maxn+1;
  for(int s = mask; s; s = (s-1)&mask)
    if(ind[s]) {
      int v = dp(mask^s) + 1;
      if(v < ans) { ans = v; best[mask] = s; }
    }
  return ans;
}

// mark the set 'mask' with color c
void mark(int mask, int c) {
  for(int i = 0; i < maxn; i++)
    if(mask & (1<<i)) label[i] = c;
}

int main() {
  while(scanf("%d", &m) == 1) {
    memset(G, 0, sizeof(G));
    int useful = 0;
    for(int i = 0; i < m; i++) {
      char r1[9], r2[9];
      scanf("%s%s", r1, r2);
      u[i] = r1[0]-'L', v[i] = r2[0]-'L';
      G[u[i]][v[i]] = 1;
      useful |= (1<<u[i]);
      useful |= (1<<v[i]);
    }

    // find the independent sets
    memset(ind, 0, sizeof(ind));
    for(int s = useful; s; s = (s-1)&useful)
      if(independent(s)) ind[s] = true;

    // dp
    memset(d, -1, sizeof(d));
    int ans = dp(useful);
    printf("%d\n", ans-2);

    // construct the answer
    int s = useful, k = 0;
    while(s) {
      mark(s, k++);
      s ^= best[s];
    }
    for(int i = 0; i < m; i++) {
      if(label[u[i]] < label[v[i]]) swap(u[i], v[i]);
      printf("%c %c\n", 'L'+u[i], 'L'+v[i]);
    }    
  }
  return 0;
}
