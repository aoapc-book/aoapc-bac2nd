// n皇后问题：普通回溯法
// Rujia Liu

#include<cstdio>
using namespace std;

int C[50], tot = 0, n = 8, nc = 0;

void search(int cur) {
  int i, j;
  nc++;
  if(cur == n) {
    tot++;
  } else for(i = 0; i < n; i++) {
    int ok = 1;
    C[cur] = i;
    for(j = 0; j < cur; j++)
      if(C[cur] == C[j] || cur-C[cur] == j-C[j] || cur+C[cur] == j+C[j]) {
        ok = 0;
        break;
      }
    if(ok) search(cur+1);
  }
}

int main() {
  scanf("%d", &n);
  search(0);
  printf("%d\n", tot);
  printf("%d\n", nc);
  return 0;
}
