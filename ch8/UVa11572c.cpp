// UVa11572 Unique snowflakes
// Rujia Liu
// 算法二：记录位置i的上个相同元素位置last[i]。使用hash_map（gcc扩展）
#include<cstdio>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx; // hash_map

const int maxn = 1000000 + 5;
int A[maxn], last[maxn];
hash_map<int, int> cur;

int main() {
  int T, n;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    cur.clear();
    for(int i = 0; i < n; i++) {
      scanf("%d", &A[i]);
      if(!cur.count(A[i])) last[i] = -1;
      else last[i] = cur[A[i]];
      cur[A[i]] = i;
    }

    int L = 0, R = 0, ans = 0;
    while(R < n) {
      while(R < n && last[R] < L) R++;
      ans = max(ans, R - L);
      L++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
