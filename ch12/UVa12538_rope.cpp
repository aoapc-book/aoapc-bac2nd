// UVa12538 Version Controlled IDE
// Rujia Liu
// This code makes use of rope, a persistent string available in gcc's STL extensions.
#include<cstdio>
#include<iostream>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;

const int maxn = 50000 + 5;
const int maxlen = 100000 + 5;

crope cur, versions[maxn];
char s[maxlen];

int main() {
  int n;
  scanf("%d", &n); // a single test case
  int d = 0;
  int vnow = 0;
  while(n--) {
    int op, p, c, v;
    scanf("%d", &op);
    if(op == 1) {
      scanf("%d%s", &p, s);
      p -= d;
      cur.insert(p, s);
      versions[++vnow] = cur;
    }
    else if(op == 2) {
      scanf("%d%d", &p, &c);
      p -= d; c -= d;
      cur.erase(p-1, c);
      versions[++vnow] = cur;
    }
    else {
      scanf("%d%d%d", &v, &p, &c);
      p -= d; v -= d; c -= d;
      crope r = versions[v].substr(p-1, c);
      d += count(r.begin(), r.end(), 'c');
      cout << r << "\n";
    }
  }
  return 0;
}
