// UVa1627 Team them up!
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;

int n, G[maxn][maxn], color[maxn], diff[maxn], cc;
vector<int> team[maxn][2]; // team[cc][c] is the list of people in connected-component cc, color c

// returns false if not bipartite graph
bool dfs(int u, int c) {
  color[u] = c;
  team[cc][c-1].push_back(u);
  for(int v = 0; v < n; v++) {
    if(u != v && !(G[u][v] && G[v][u])) { // u and v must be in different groups
      if(color[v] > 0 && color[v] == color[u]) return false;
      if(!color[v] && !dfs(v, 3-c)) return false;
    }
  }
  return true;
}

bool build_graph() {
  memset(color, 0, sizeof(color));
  cc = 0; // current connected-component
  for(int i = 0; i < n; i++)
    if(!color[i]) {
      team[cc][0].clear();
      team[cc][1].clear();
      if(!dfs(i, 1)) return false;
      diff[cc] = team[cc][0].size() - team[cc][1].size();
      cc++;
    }

  return true;
}

// d[i][j+n] = 1 iff we can arrange first i cc so that team 1 has j more people than team 2.
int d[maxn][maxn*2], teamno[maxn]; 

void print(int ans) {
  vector<int> team1, team2;
  for(int i = cc-1; i >= 0; i--) {
    int t;
    if(d[i][ans-diff[i]+n]) { t = 0; ans -= diff[i]; }
    else { t = 1; ans += diff[i]; }
    for(int j = 0; j < team[i][t].size(); j++)
      team1.push_back(team[i][t][j]);
    for(int j = 0; j < team[i][1^t].size(); j++)
      team2.push_back(team[i][1^t][j]);
  }
  printf("%d", team1.size());
  for(int i = 0; i < team1.size(); i++) printf(" %d", team1[i]+1);
  printf("\n");

  printf("%d", team2.size());
  for(int i = 0; i < team2.size(); i++) printf(" %d", team2[i]+1);
  printf("\n");
}

void dp() {
  memset(d, 0, sizeof(d));
  d[0][0+n] = 1;
  for(int i = 0; i < cc; i++)
    for(int j = -n; j <= n; j++) if(d[i][j+n]) {
      d[i+1][j+diff[i]+n] = 1;
      d[i+1][j-diff[i]+n] = 1;
    }
  for(int ans = 0; ans <= n; ans++) {
    if(d[cc][ans+n]) { print(ans); return; }
    if(d[cc][-ans+n]) { print(-ans); return; }
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    memset(G, 0, sizeof(G));
    for(int u = 0; u < n; u++) {
      int v;
      while(cin >> v && v) G[u][v-1] = 1;
    }

    if(n == 1 || !build_graph()) cout << "No solution\n";
    else dp();

    if(T) cout << "\n";
  }
  return 0;
}
