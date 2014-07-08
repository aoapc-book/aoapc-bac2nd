// UVa12099 The Bookcase
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 70 + 5;
const int maxw = 30;
const int INF = 1000000000;

struct Book {
  int h, w;
  bool operator < (const Book& rhs) const {
    return h > rhs.h || (h == rhs.h && w > rhs.w);
  }
} books[maxn];

// We sort books in decreasing order of heights and place them one by one
// So level 1's height is book 1's height
// dp[i][j][k] is the minimal total heights of level 2 and 3 when we used i books, level 2 and 3's total widths are j and k,
// level 1's width is (sumw[n] - j - k)
int dp[2][maxn*maxw][maxn*maxw];
int sumw[maxn]; // sum[i] is the sum of widths of first i books. sum[0] = 0.

// increased height if you place a book with height h to a level with width w
// if w == 0, that means the level if empty, so height is increased by h
// otherwise, the height is unchanged because we're adding books in decreasing order of height
inline int f(int w, int h) {
  return w == 0 ? h : 0;
}

inline void update(int& newd, int d) {
  if(newd < 0 || d < newd) newd = d;
}

int main () {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d%d", &books[i].h, &books[i].w);
    sort(books, books+n);

    sumw[0] = 0;
    for(int i = 1; i <= n; i++)
      sumw[i] = sumw[i-1] + books[i-1].w;
    
    dp[0][0][0] = 0;
    int t = 0;
    for(int i = 0; i < n; i++) {
      // Don't use memset. It's too slow
      for(int j = 0; j <= sumw[i+1]; j++)
        for(int k = 0; k <= sumw[i+1]-j; k++) dp[t^1][j][k] = -1;

      for(int j = 0; j <= sumw[i]; j++)
        for(int k = 0; k <= sumw[i]-j; k++) if(dp[t][j][k] >= 0) {
          update(dp[t^1][j][k], dp[t][j][k]); // level 1
          update(dp[t^1][j+books[i].w][k], dp[t][j][k] + f(j,books[i].h)); // level 2
          update(dp[t^1][j][k+books[i].w], dp[t][j][k] + f(k,books[i].h)); // level 3
        }
      t ^= 1;
    }

    int ans = INF;
    for(int j = 1; j <= sumw[n]; j++) // each level has at least one book
      for(int k = 1; k <= sumw[n]-j; k++) if(dp[t][j][k] >= 0) {
        int w = max(max(j, k), sumw[n]-j-k);
        int h = books[0].h + dp[t][j][k];
        ans = min(ans, w * h);
      }
    printf("%d\n", ans);
  }
  return 0;
}
