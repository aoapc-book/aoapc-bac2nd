// n皇后问题：生成-测试法
// Rujia Liu
#include<cstdio>
using namespace std;

int C[50], tot = 0, n = 8, nc = 0;

void search(int cur) {
  int i, j;
  nc++;
  if(cur == n) {
    for(i = 0; i < n; i++)
      for(j = i+1; j < n; j++)
        if(C[i] == C[j] || i-C[i] == j-C[j] || i+C[i] == j+C[j]) return;
    tot++;
  } else for(i = 0; i < n; i++) {
    C[cur] = i;
    search(cur+1);
  }
}

int main() {
  scanf("%d", &n);
  search(0);
  printf("%d\n", tot);
  printf("%d\n", nc);
  return 0;
}
