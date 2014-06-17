// UVa1442 Cav
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000000 + 5;
int n, p[maxn], s[maxn], h[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    for(int i = 0; i < n; i++) scanf("%d", &s[i]);

    int ans = 0, level = s[0];
    for(int i = 0; i < n; i++) {
      if(p[i] > level) level = p[i];
      if(s[i] < level) level = s[i];
      h[i] = level;
    }
    level = s[n-1];
    for(int i = n-1; i >= 0; i--) {
      if(p[i] > level) level = p[i];
      if(s[i] < level) level = s[i];
      ans += min(h[i], level) - p[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
