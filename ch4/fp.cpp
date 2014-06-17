#include<stdio.h>

/*
   演示一些浮点误差
   在笔者的环境下，运行结果为：
0.9999990
0.2499998
0.2
*/

int main() {
  double f;
  for(f = 2; f > 1; f -= 1e-6);
  printf("%.7f\n", f);
  printf("%.7f\n", f / 4);
  printf("%.1f\n", f / 4);
  return 0;
}
