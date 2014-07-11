// UVa1204 Fun Game
// Rujia Liu
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)

const int maxn = 16;
const int maxlen = 100 + 5;

// the overlap length of a (left) and b (right)
int calc_overlap(const string& a, const string& b) {
  int n1 = a.length();
  int n2 = b.length();
  for(int i = 1; i < n1; i++) { // place b at position i
    if(n2 + i <= n1) continue; // b cannot extend to the right of a
    bool ok = true;
    for(int j = 0; i + j < n1; j++)
      if(a[i+j] != b[j]) { ok = false; break; }
    if(ok) return n1 - i;
  }
  return 0;
}

struct Item {
  string s, rev;
  bool operator < (const Item& rhs) const {
    return s.length() < rhs.s.length();
  }
};

int n;
string s[maxn][2];
int len[maxn];
int overlap[maxn][maxn][2][2];

void init() {
  // read input
  Item tmp[maxn];
  REP(i,n) {
    cin >> tmp[i].s;
    tmp[i].rev = tmp[i].s;
    reverse(tmp[i].rev.begin(), tmp[i].rev.end());
  }

  // remove strings that are occurred in another string
  int n2 = 0;
  sort(tmp, tmp+n);
  REP(i,n) {
    bool need = true;
    for(int j = i+1; j < n; j++) {
      if(tmp[j].s.find(tmp[i].s) != string::npos ||
         tmp[j].rev.find(tmp[i].s) != string::npos) { need = false; break; }
    }
    if(need) {
      s[n2][0] = tmp[i].s; s[n2][1] = tmp[i].rev;
      len[n2] = tmp[i].s.length();
      n2++;
    }
  }
  n = n2;

  // calculate overlaps
  REP(i,n) REP(j,n) REP(x,2) REP(y,2)
    overlap[i][j][x][y] = calc_overlap(s[i][x] , s[j][y]);
}

// d[s][i][x] is the minimal total length if we used set s and the last string is s[i][x]
int d[1<<maxn][maxn][2];

inline void update(int& x, int v) {
  if(x < 0 || v < x) x = v;
}

void solve() {
  // dp
  memset(d, -1, sizeof(d));
  d[1][0][0] = len[0]; // always use string s[0][0] first
  int full = (1<<n) - 1;
  for(int s = 1; s < full; s++) {
    REP(i,n) REP(x,2) if(d[s][i][x] >= 0)
      for(int j = 1; j < n; j++) // place j
        if(!(s & (1<<j)))
          REP(y,2) update(d[s|(1<<j)][j][y], d[s][i][x]+len[j]-overlap[i][j][x][y]);
  }

  // find answer
  int ans = -1;
  REP(i,n) REP(x,2) {
    if(d[full][i][x] < 0) continue;
    update(ans, d[full][i][x]-overlap[i][0][x][0]);
  }
  if(ans <= 1) ans = 2; // problem said: at least two children

  cout << ans << "\n";
}

int main() {
  while(cin >> n && n) {
    init();
    solve();
  }
  return 0;
}
