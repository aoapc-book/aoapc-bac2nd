// UVa10817 Headmaster's Headache
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
using namespace std;

const int maxn = 100 + 20 + 5;
const int maxs = 8;
const int INF = 1000000000;
int m, n, s, c[maxn], st[maxn], d[maxn][1<<maxs][1<<maxs];

// s1是一个人教的科目集合，s2是两个人教的科目集合
int dp(int i, int s0, int s1, int s2) {
  if(i == m+n) return s2 == (1<<s) - 1 ? 0 : INF;
  int& ans = d[i][s1][s2];
  if(ans >= 0) return ans;

  ans = INF;
  if(i >= m) ans = dp(i+1, s0, s1, s2); // 不选

  // 选
  int m0 = st[i] & s0, m1 = st[i] & s1;
  s0 ^= m0;
  s1 = (s1 ^ m1) | m0;
  s2 |= m1;
  ans = min(ans, c[i] + dp(i+1, s0, s1, s2));
  return ans;
}

int main() {
  int x;
  string line;
  while(getline(cin, line)) {
    stringstream ss(line);
    ss >> s >> m >> n;
    if(s == 0) break;

    for(int i = 0; i < m+n; i++) {
      getline(cin, line);
      stringstream ss(line);
      ss >> c[i];
      st[i] = 0;
      while(ss >> x) st[i] |= (1 << (x-1));
    }
    memset(d, -1, sizeof(d));
    cout << dp(0, (1<<s)-1, 0, 0) << "\n";
  }
  return 0;
}
