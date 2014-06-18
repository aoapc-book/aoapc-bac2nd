// UVa247 Calling Circles
// Rujia Liu
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
using namespace std;

vector<string> names;
int ID(const string& s) {
  for(int i = 0; i < names.size(); i++)
    if(names[i] == s) return i;
  names.push_back(s);
  return names.size() - 1;
}

const int maxn = 25 + 5;
int n, m, vis[maxn], d[maxn][maxn];
void dfs(int u) {
  vis[u] = 1;
  for(int v = 0; v < n; v++)
    if(!vis[v] && d[u][v] && d[v][u]) {
      printf(", %s", names[v].c_str());
      dfs(v);
    }
}

int main() {
  char s1[99], s2[99];
  int kase = 0;
  while(scanf("%d%d", &n, &m) == 2 && n) {
    names.clear();
    memset(d, 0, sizeof(d));
    for(int i = 0; i < n; i++) d[i][i] = 1;
    while(m--) {
      scanf("%s%s", s1, s2);
      d[ID(s1)][ID(s2)] = 1;
    }
    for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          d[i][j] |= d[i][k] && d[k][j];

    if(kase > 0) printf("\n");
    printf("Calling circles for data set %d:\n", ++kase);

    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
      if(!vis[i]) {
        printf("%s", names[i].c_str());
        dfs(i);
        printf("\n");
      }
  }
  return 0;
}
