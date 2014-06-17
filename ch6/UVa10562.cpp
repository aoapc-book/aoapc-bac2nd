// UVa10562 Undraw the Trees
// Rujia Liu
// 题意：把画得挺好看的多叉树转化为括号表示法
// 算法：直接在二维字符数组里递归。注意空树，并且结点标号可以是任意可打印字符

#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

const int maxn = 200 + 10;
int n;
char buf[maxn][maxn];

// 递归遍历并且输出以字符buf[r][c]为根的树
void dfs(int r, int c) {
  printf("%c(", buf[r][c]);
  if(r+1 < n && buf[r+1][c] == '|') { // 有子树
    int i = c;
    while(i-1 >= 0 && buf[r+2][i-1] == '-') i--; // 找"----"的左边界
    while(buf[r+2][i] == '-' && buf[r+3][i] != '\0') {
      if(!isspace(buf[r+3][i])) dfs(r+3, i); // fgets读入的'\n'也满足isspace()
      i++;
    }
  }
  printf(")");
}

void solve() {
  n = 0;
  for(;;) {
    fgets(buf[n], maxn, stdin);
    if(buf[n][0] == '#') break; else n++;
  }
  printf("(");
  if(n) {
    for(int i = 0; i < strlen(buf[0]); i++)
      if(buf[0][i] != ' ') { dfs(0, i); break; }
  }
  printf(")\n");
}

int main() {
  int T;
  fgets(buf[0], maxn, stdin);
  sscanf(buf[0], "%d", &T);
  while(T--) solve();
  return 0;
}
