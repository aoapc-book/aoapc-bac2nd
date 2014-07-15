// UVa1375 The Best Name for Your Baby
// Rujia Liu
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;

const int maxn = 50 + 5;
const int maxlen = 20 + 5;
const int maxs = 50*20 + 52 + 5; // for a rule with right length x, we have x-1 symbols with length>1

int n, L, ns;
string rule[maxn];
string sym[maxs]; // symbols
int car[maxs], cdr[maxs]; // lisp names for "head" and "tail" 8-)
string dp[maxs][maxlen];

bool is_all_terminal(const string& s) {
  for(int i = 0; i < s.length(); i++)
    if(!(s[i] >= 'a' && s[i] <= 'z')) return false;
  return true;
}

string min(const string& a, const string& b) {
  if(a == "-") return b;
  return a < b ? a : b;
}

struct Node {
  int x;
  string s;
  Node(int x, string s):x(x),s(s){}
  // smaller string has higher priority, thus will be extracted earlier
  bool operator < (const Node& rhs) const {
    return s > rhs.s;
  }
};

struct Transform {
  int target, empty;
  Transform(int t, int e):target(t),empty(e){}
};

vector<Transform> tr[maxs];

bool vis[maxs];
// fill in other dp[?][len] reachable from existing dp[?][len] nodes via "epsilon edges"
void search(int len) {
  memset(vis, 0, sizeof(vis));
  priority_queue<Node> q;
  for(int i = 0; i < ns; i++)
    if(dp[i][len] != "-") {
      q.push(Node(i, dp[i][len]));
    }

  while(!q.empty()) {
    Node u = q.top(); q.pop();
    int x = u.x;
    string s = u.s;
    if(vis[x]) continue;
    vis[x] = true;
    for(int i = 0; i < tr[x].size(); i++) {
      int target = tr[x][i].target;
      int empty = tr[x][i].empty;
      if(dp[empty][0] == "" && (dp[target][len] == "-" || s < dp[target][len])) {
        dp[target][len] = s;
        q.push(Node(target, s));
      }
    }
  }
}

map<string,int> sym2id;

int ID(const string& s) {
  if(!sym2id.count(s)) {
    sym[ns] = s;
    sym2id[s] = ns++;
  }
  return sym2id[s];
}

// S=HT, if H can be empty, S and T can be transformed to each other
// we say h can reach s via epsilon edge t, and t can reach s via epsilon edge h
void add_intermediate_symbol(const string& S) {
  int s = ID(S);
  if(S.length() < 2) return;
  int h = ID(S.substr(0,1));
  int t = ID(S.substr(1,S.length()-1));
  tr[h].push_back(Transform(s, t));
  tr[t].push_back(Transform(s, h));
  car[s] = h;
  cdr[s] = t;
}

int main() {
  while(cin >> n >> L && n) {
    sym2id.clear();
    ns = 0;

    ID(""); // make sure sym[0] = ""
    for(int i = 0; i < maxs; i++) tr[i].clear();

    for(int i = 0; i < n; i++) {
      cin >> rule[i]; // for example, rule[i]="S=AbC"
      int left = ID(rule[i].substr(0,1));
      int right = ID(rule[i].substr(2));
      tr[right].push_back(Transform(left, ID("")));  // AbC can be transformed to S
      int len = rule[i].length();
      for(int j = 2; j < len; j++) // AbC, bC, C
        add_intermediate_symbol(rule[i].substr(j));
    }

    for(int i = 0; i < ns; i++)
      for(int j = 0; j <= L; j++)
        dp[i][j] = "-"; // impossible
    dp[0][0] = ""; // dp[i][j] means the first string with len j that symbol i can be transformed into

    for(int j = 0; j <= L; j++) {
      for(int i = 0; i < ns; i++) {
        if(sym[i].length() == j && is_all_terminal(sym[i])) dp[i][j] = sym[i];
        if(sym[i].length() < 2) continue;
        int s1 = car[i], s2 = cdr[i];
        for(int k = 1; k < j; k++) {
          if(dp[s1][k] != "-" && dp[s2][j-k] != "-")
            dp[i][j] = min(dp[i][j], dp[s1][k] + dp[s2][j-k]);
        }
      }
      search(j);
    }
    cout << dp[ID("S")][L] << "\n";
  }
  return 0;
}
