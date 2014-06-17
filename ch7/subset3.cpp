// {0~n-1}的所有子集：二进制法
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int s) {  // 打印{0, 1, 2, ..., n-1}的子集S
  for(int i = 0; i < n; i++)
    if(s&(1<<i)) printf("%d ", i); // 这里利用了C语言“非0值都为真”的规定
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < (1<<n); i++)  // 枚举各子集所对应的编码 0, 1, 2, ..., 2^n-1
    print_subset(n, i);
  return 0;
}
