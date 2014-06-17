// 可重集的全排列
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

int P[100], A[100];

// 输出数组P中元素的全排列。数组P中可能有重复元素
void print_permutation(int n, int* P, int* A, int cur) {
  if(cur == n) {
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
  } else for(int i = 0; i < n; i++) if(!i || P[i] != P[i-1]) {
    int c1 = 0, c2 = 0;
    for(int j = 0; j < cur; j++) if(A[j] == P[i]) c1++;
    for(int j = 0; j < n; j++) if(P[i] == P[j]) c2++;
    if(c1 < c2) {
      A[cur] = P[i];
      print_permutation(n, P, A, cur+1);
    }
  }
}

int main() {
  int i, n;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &P[i]);
  sort(P, P+n);
  print_permutation(n, P, A, 0);
  return 0;
}
