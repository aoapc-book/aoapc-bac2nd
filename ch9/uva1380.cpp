// UVa1380 A Scheduling Problem
// Rujia Liu
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 200 + 5;
const int INF = 1000000000;

struct Edge {
  int u, v, d; // d=1 means u->v, d=2 means v->u, d=0 means u-v
  Edge(int u=0, int v=0, int d=0):u(u),v(v),d(d){}
};

vector<Edge> edges[maxn];
int n, root, maxlen, f[maxn], g[maxn], have_father[maxn];

// maximal length of a DIRECTED path starting from u
int dfs(int u) {
  int ans = 0;
  for(int i = 0; i < edges[u].size(); i++) {
    int v = edges[u][i].v;
    if(edges[u][i].d == 1)
      ans = max(ans, dfs(v)+1);
  }
  return ans;
}

bool read_data() {
  bool have_data = false;
  int a, b;
  n = 0;
  for(int i = 0; i < maxn; i++) edges[i].clear();
  memset(have_father, 0, sizeof(have_father));

  while(cin >> a && a){
    string str;
    have_data = true;
    if(a > n) n = a;
    while(cin >> str && str != "0"){
      int len = str.length();
      char dir = str[len-1];
      if(dir == 'd' || dir == 'u') str = str.substr(0, len-1);
      stringstream ss(str);
      ss >> b; // b is a's son
      if(b > n) n = b;
      have_father[b] = 1;
      if(dir == 'd'){
        edges[a].push_back(Edge(a, b, 1)); // forward
        edges[b].push_back(Edge(b, a, 2)); // backward
      }else if(dir == 'u'){
        edges[a].push_back(Edge(a, b, 2));
        edges[b].push_back(Edge(b, a, 1));
      }else{
        edges[a].push_back(Edge(a, b, 0)); // it's a rooted tree, so we don't store edge to father
      }
    }
  }
  if(have_data) {
    for(int i = 1; i <= n; i++)
      if(!have_father[i] && !edges[i].empty()) { root = i; break; }
  }
  return have_data;
}

struct UndirectedSon {
  int w, f, g;
  UndirectedSon(int w=0, int f=0, int g=0):w(w),f(f),g(g){}
};

bool cmp_f(const UndirectedSon& w1, const UndirectedSon& w2) {
  return w1.f < w2.f;
}

bool cmp_g(const UndirectedSon& w1, const UndirectedSon& w2) {
  return w1.g < w2.g;
}

// calculate f[i] and g[i]
// return true iff f[i] < INF
// f[i] is the minimal length of the longest "->u" path if all subtree paths have length <= maxlen
// g[i] is the minimal length of the longest "u->" path if all subtree paths have length <= maxlen
// f[i] = g[i] = INF if "all subtree paths have length <= maxlen" cannot be satisfied
bool dp(int i, int fa) {
  if(edges[i].empty()) {
    f[i] = g[i] = 0;
    return true;
  }
  vector<UndirectedSon> sons;
  int f0 = 0, g0 = 0; // f'[i] and g'[i] for directed sons

  // let f'[i] = max{f[w] | w->i}+1, g'[i] = max{g[w] | i->w}+1
  // then we should change some undirected edges to ->u or u-> edges so that f'[i]+g'[i] <= maxlen
  // then f[i] is the minimal f'[i] under this condition, and g[i] is the minimal g'[i]
  for(int k = 0; k < edges[i].size(); k++) {
    int w = edges[i][k].v;
    if(w == fa) continue;
    dp(w, i);
    int d = edges[i][k].d;
    if(d == 0) sons.push_back(UndirectedSon(w, f[w], g[w]));
    else if(d == 1) g0 = max(g0, g[w]+1);
    else f0 = max(f0, f[w]+1);
  }
  // If there is no undirected edges, we're done
  if(sons.empty()) {
    f[i] = f0; g[i] = g0;
    if(f[i] + g[i] > maxlen) { f[i] = g[i] = INF; }
    return f[i] < INF;
  }

  f[i] = g[i] = INF;

  // to calculate f[i], we sort f[w] of undirected sons in increasing order and make first p edges to w->i
  // then we calculate f'[i] and g'[i], check for f'[i]+g'[i] <= maxlen and update answer
  int s = sons.size();
  sort(sons.begin(), sons.end(), cmp_f);
  int maxg[maxn]; // maxg[i] is max{sons[i].g, sons[i+1].g, ...}
  maxg[s-1] = sons[s-1].g;
  for(int k = s-2; k >= 0; k--)
    maxg[k] = max(sons[k].g, maxg[k+1]);
  for(int p = 0; p <= sons.size(); p++) {
    int ff = f0, gg = g0;
    if(p > 0) ff = max(ff, sons[p-1].f+1);
    if(p < sons.size()) gg = max(gg, maxg[p]+1);
    if(ff + gg <= maxlen) f[i] = min(f[i], ff);
  }

  // g[i] is similar
  sort(sons.begin(), sons.end(), cmp_g);
  int maxf[maxn]; // maxf[i] is max{sons[i].f, sons[i+1].f, ...}
  maxf[s-1] = sons[s-1].f;
  for(int k = s-2; k >= 0; k--)
    maxf[k] = max(sons[k].f, maxf[k+1]);
  for(int p = 0; p <= sons.size(); p++) {
    int ff = f0, gg = g0;
    if(p > 0) gg = max(gg, sons[p-1].g+1);
    if(p < sons.size()) ff = max(ff, maxf[p]+1);
    if(ff + gg <= maxlen) g[i] = min(g[i], gg);
  }

  return f[i] < INF;
}

int main() {
  while(read_data()) {    
    maxlen = 0;
    for(int i = 1; i <= n; i++) maxlen = max(maxlen, dfs(i));
    // Note: the problem asks for the number of nodes in path, but all the "lengths" above mean "number of edges"
    if(dp(root, -1)) cout << maxlen+1 << "\n"; 
    else cout << maxlen+2 << "\n";
  }
  return 0;
}
