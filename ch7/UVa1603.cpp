// UVa1603 Square Destroyer
// Rujia Liu
// This code implements a variant of an algorithm presented in a book. It's simple yet efficient.
// Readers are encouraged to experiment on other algorithms.
// However, it's still slow for n=5 and m=0 (which is NOT in judge input)
// If you really want an efficient solution, learn DLX (Algorithm X with dancing links)
// DLX is well expained (with code) in my other book <<Beginning Algorithm Contests -- Training Guide>>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int maxs = 60; // number of squares: 25+16+9+4+1=55
const int maxm = 60; // number of matches: 2*5*(5+1)=60

int n, exists[maxm]; // matches
int s, size[maxs], fullsize[maxs], contains[maxs][maxm]; // squares
int best;

inline int row_match(int x, int y) {
  return (2*n+1)*x+y;
}

inline int col_match(int x, int y) {
  return (2*n+1)*x+n+y;
}

// number of matches in a full n*n grid
inline int match_count(int n) {
  return 2*n*(n+1);
}

void init() {
  int m, v;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < match_count(n); ++i) exists[i] = 1;
  while(m--) {
    scanf("%d", &v);
    exists[v-1] = 0;
  }

  // collect full squares
  s = 0;
  memset(contains, 0, sizeof(contains));
  for(int i = 1; i <= n; i++) // side length
    for(int x = 0; x <= n-i; x++)
      for(int y = 0; y <= n-i; y++) {
        size[s] = 0;
        fullsize[s] = 4*i; // number of matches in a complete square
        for(int j = 0; j < i; j++) {
          int a = row_match(x, y+j); // up
          int b = row_match(x+i, y+j); // down
          int c = col_match(x+j, y); // left
          int d = col_match(x+j, y+i); // right
          contains[s][a] = 1;
          contains[s][b] = 1;
          contains[s][c] = 1;
          contains[s][d] = 1;
          size[s] += exists[a] + exists[b] + exists[c] + exists[d]; // number of matches now
        }
        ++s;
      }
}

int find_square() {
  for(int i = 0; i < s; i++)
    if(size[i] == fullsize[i]) return i;
  return -1;
}

void dfs(int dep) {
  if(dep >= best) return;

  int k = find_square();
  if(k == -1) {
    best = dep;
    return;
  }

  // remove a match in that square
  for(int i = 0; i < match_count(n); i++)
    if(contains[k][i]) {
      for(int j = 0; j < s; j++)
        if(contains[j][i]) size[j]--;
      dfs(dep + 1);
      for(int j = 0; j < s; j++)
        if(contains[j][i]) size[j]++;
    }
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    init();
    best = n*n;
    dfs(0);
    printf("%d\n", best);
  }
  return 0;
}
