// UVa1471 Defense Lines
// Rujia Liu
// Algorithm 1: use STL set to maintain the candidates.
// This is a little bit more intuitive, but less efficient (than algorithm 2)
#include<cstdio>
#include<set>
#include<cassert>
using namespace std;

const int maxn = 200000 + 5;
int n, a[maxn], f[maxn], g[maxn];

struct Candidate {
  int a, g;
  Candidate(int a, int g):a(a),g(g) {}
  bool operator < (const Candidate& rhs) const {
    return a < rhs.a;
  }
};

set<Candidate> s;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    if(n == 1) { printf("1\n"); continue; }

    // g[i] is the length of longest increasing continuous subsequence ending at i
    g[0] = 1;
    for(int i = 1; i < n; i++)
      if(a[i-1] < a[i]) g[i] = g[i-1] + 1;
      else g[i] = 1;

    // f[i] is the length of longest increasing continuous subsequence starting from i
    f[n-1] = 1;
    for(int i = n-2; i >= 0; i--)
      if(a[i] < a[i+1]) f[i] = f[i+1] + 1;
      else f[i] = 1;

    s.clear();
    s.insert(Candidate(a[0], g[0]));
    int ans = 1;
    for(int i = 1; i < n; i++) {
      Candidate c(a[i], g[i]);
      set<Candidate>::iterator it = s.lower_bound(c); // first one that is >= c
      bool keep = true;
      if(it != s.begin()) {
        Candidate last = *(--it); // (--it) points to the largest one that is < c
        int len = f[i] + last.g; 
        ans = max(ans, len);
        if(c.g <= last.g) keep = false;
      }

      if(keep) {
        s.erase(c); // if c.a is already present, the old g must be <= c.g
        s.insert(c);
        it = s.find(c); // this is a bit cumbersome and slow but it's clear
        it++;
        while(it != s.end() && it->a > c.a && it->g <= c.g) s.erase(it++);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
