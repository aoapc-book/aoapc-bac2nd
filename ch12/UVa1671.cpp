// UVa1671 History of Languages
// Rujia Liu
//
// This is Problem 12-1 of <<Beginning Algorithm Contests>> 2nd edition
//
// We want to test whether A intersects with ~B (finalA = 1, finalB = 0), or B intersects with ~A (finalA = 0, finalB = 1)
// So we can do a single DFS instead of two, checking finalA XOR finals B=1
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 2000 + 5;
const int maxt = 26;

// Note: state 0 is a dummy state, other states' number is increased by 1
struct DFA {
  int n;
  int is_final[maxn];
  int next[maxn][maxt];
  void read(int t) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &is_final[i]);
      for(int c = 0; c < t; c++) {
        int s;
        scanf("%d", &s);
        next[i][c] = s+1;
      }
    }
    is_final[0] = 0; // dummy state is not final
  }
}A, B;

int vis[maxn][maxn], kase, t;

// try to find a common string starting from (s1, s2)
bool dfs(int s1, int s2) {
  vis[s1][s2] = kase;
  if(A.is_final[s1] ^ B.is_final[s2]) return true;
  for(int i = 0; i < t; i++) {
    int nexta = A.next[s1][i];
    int nextb = B.next[s2][i];
    if(vis[nexta][nextb] != kase && dfs(nexta, nextb)) return true;
  }
  return false;
}

int main() {
  kase = 0;
  memset(vis, 0, sizeof(vis));
  while(scanf("%d", &t) == 1 && t) {
    A.read(t);
    B.read(t);
    printf("Case #%d: ", ++kase);
    if(dfs(1, 1)) printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}
