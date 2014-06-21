// UVa11584 Partitioning by Palindromes
// Rujia Liu
// This code is slightly different from the book.
// It uses memoization to judge whether s[i..j] is a palindrome.
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;
int n, kase, vis[maxn][maxn], p[maxn][maxn], d[maxn];
char s[maxn];

int is_palindrome(int i, int j) {
  if(i >= j) return 1;
  if(s[i] != s[j]) return 0;

  if(vis[i][j] == kase) return p[i][j];
  vis[i][j] = kase;
  p[i][j] = is_palindrome(i+1, j-1);
  return p[i][j];
}

int main() {
  int T;
  scanf("%d", &T);
  memset(vis, 0, sizeof(vis));
  for(kase = 1; kase <= T; kase++) {
    scanf("%s", s+1);
    n = strlen(s+1);
    d[0] = 0;
    for(int i = 1; i <= n; i++) {
      d[i] = i+1;
      for(int j = 0; j < i; j++)
        if(is_palindrome(j+1, i)) d[i] = min(d[i], d[j] + 1);
    }
    printf("%d\n", d[n]);
  }
  return 0;
}
