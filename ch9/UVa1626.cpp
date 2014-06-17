// LA2451 Brackets Sequence
// Rujia Liu
// 算法：形如(S)或者[S]，转移到d(S)，然后分成AB，转移到d(A)+d(B)。注意(S, [S, )S之类全部属于第二种转移。
// 注意输入有空行。
// 本程序是递推解法
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

void dp() {
  for(int i = 0; i < n; i++) {
    d[i+1][i] = 0;
    d[i][i] = 1;
  }
  for(int i = n-2; i >= 0; i--)
    for(int j = i+1; j < n; j++) {
      d[i][j] = n;
      if(match(S[i], S[j])) d[i][j] = min(d[i][j], d[i+1][j-1]);
      for(int k = i; k < j; k++)
        d[i][j] = min(d[i][j], d[i][k] + d[k+1][j]);
    }
}

void print(int i, int j) {
  if(i > j) return ;
  if(i == j) {
    if(S[i] == '(' || S[i] == ')') printf("()");
    else printf("[]");
    return;
  }
  int ans = d[i][j];
  if(match(S[i], S[j]) && ans == d[i+1][j-1]) {
    printf("%c", S[i]); print(i+1, j-1); printf("%c", S[j]);
    return;
  }
  for(int k = i; k < j; k++)
    if(ans == d[i][k] + d[k+1][j]) {
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
    dp();
    print(0, n-1);
    printf("\n");
    if(T) printf("\n");
    readline(S);
  }
  return 0;
}
