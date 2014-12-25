// UVa1220 Party at Hali-Bula
// Rujia Liu
//
// rev 2: fixed bug reported by EndlessCheng
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int maxn = 200 + 5;

int cnt;
vector<int> sons[maxn];
int n, d[maxn][2], f[maxn][2];

map<string, int> dict;
int ID(const string& s) {
  if(!dict.count(s)) dict[s] = cnt++;
  return dict[s];
}

int dp(int u, int k) {
  f[u][k] = 1;
  d[u][k] = k;
  for(int i = 0; i < sons[u].size(); i++) {
    int v = sons[u][i];
    if(k == 1) {
      d[u][1] += dp(v, 0);
      if(!f[v][0]) f[u][1] = 0;
    } else {
      d[u][0] += max(dp(v, 0), dp(v, 1));
      if(d[v][0] == d[v][1]) f[u][k] = 0;
      else if(d[v][0] > d[v][1] && !f[v][0]) f[u][k] = 0;
      else if(d[v][1] > d[v][0] && !f[v][1]) f[u][k] = 0;
    }
  }
  return d[u][k];
}

int main() {
  string s, s2;
  while(cin >> n >> s) {
    cnt = 0;
    dict.clear();
    for(int i = 0; i < n; i++) sons[i].clear();

    ID(s);
    for(int i = 0; i < n-1; i++) {
      cin >> s >> s2;
      sons[ID(s2)].push_back(ID(s));
    }
    printf("%d ", max(dp(0, 0), dp(0, 1)));
    bool unique = false;
    if(d[0][0] > d[0][1] && f[0][0]) unique = true;
    if(d[0][1] > d[0][0] && f[0][1]) unique = true;
    if(unique) printf("Yes\n"); else printf("No\n");
  }
  return 0;
}
