// UVa10048 Audiophobia
// Rujia Liu
// 题意：输入一个无项带权图，回答一些询问，询问内容是问某两点间最大权最小的路径
// 算法：变形的floyd
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
const int INF = 1000000000;
int d[maxn][maxn];

int main() {
  int n, m, Q, u, v, w, kase = 0;
  while(scanf("%d%d%d", &n, &m, &Q) == 3 && n) {
    // 初始化
    for(int i = 0; i < n; i++) {
      d[i][i] = 0;
      for(int j = i+1; j < n; j++) { d[i][j] = d[j][i] = INF; }
    }
    for(int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &w); u--; v--;
      d[u][v] = min(d[u][v], w);
      d[v][u] = d[u][v];
    }
    // 主算法
    for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          if(d[i][k] < INF && d[k][j] < INF)
            d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
    // 询问
    if(kase) printf("\n");
    printf("Case #%d\n", ++kase);
    while(Q--) {
      scanf("%d%d", &u, &v); u--; v--;
      if(d[u][v] == INF) printf("no path\n"); else printf("%d\n", d[u][v]);
    }
  }
  return 0;
}
