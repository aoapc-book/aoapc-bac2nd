// LA2451 Brackets Sequence
// Rujia Liu
// 算法：形如(S)或者[S]，转移到d(S)，然后分成AB，转移到d(A)+d(B)。注意(S, [S, )S之类全部属于第二种转移。
// 注意输入有空行。
// 本程序是记忆化解法，速度较慢，处于超时的边缘
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
char S[maxn];
int n, d[maxn][maxn];

bool match(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int dp(int i, int j) {
  if(i > j) return 0;
  if(i == j) return 1;
  int& ans = d[i][j];
  if(ans >= 0) return ans;
  ans = n;
  if(match(S[i], S[j])) ans = min(ans, dp(i+1, j-1));
  for(int k = i; k < j; k++)
    ans = min(ans, dp(i, k) + dp(k+1, j));
  return ans;
}

void print(int i, int j) {
  if(i > j) return ;
  if(i == j) {
    if(S[i] == '(' || S[i] == ')') printf("()");
    else printf("[]");
    return;
  }
  int ans = dp(i, j);
  if(match(S[i], S[j]) && ans == dp(i+1, j-1)) {
    printf("%c", S[i]); print(i+1, j-1); printf("%c", S[j]);
    return;
  }
  for(int k = i; k < j; k++)
    if(ans == dp(i, k) + dp(k+1, j)) {
      print(i, k); print(k+1, j);
      return;
    }
}

void readline(char* S) {
  fgets(S, maxn, stdin);
}

int main() {
  int T;

  readline(S);
  sscanf(S, "%d", &T);
  readline(S);

  while(T--) {
    readline(S);
    n = strlen(S) - 1;
    memset(d, -1, sizeof(d));
    print(0, n-1);
    printf("\n");
    if(T) printf("\n");
    readline(S);
  }
  return 0;
}
