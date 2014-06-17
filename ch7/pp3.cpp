// 可重集的全排列(next_permutation版)
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
  int n, p[10];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &p[i]);
  sort(p, p+n); // 排序，得到p的最小排列
  do {
    for(int i = 0; i < n; i++) printf("%d ", p[i]); // 输出排列p
    printf("\n");
  } while(next_permutation(p, p+n)); // 求下一个排列
  return 0;
}
