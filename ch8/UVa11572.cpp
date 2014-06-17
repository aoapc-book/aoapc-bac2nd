// UVa11572 Unique snowflakes
// Rujia Liu
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int maxn = 1000000 + 5;
int A[maxn];

int main() {
  int T, n;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);

    set<int> s;
    int L = 0, R = 0, ans = 0;
    while(R < n) {
      while(R < n && !s.count(A[R])) s.insert(A[R++]);
      ans = max(ans, R - L);
      s.erase(A[L++]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
