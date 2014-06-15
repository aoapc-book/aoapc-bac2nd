// UVa10082 WERTYU
// Rujia Liu
#include<stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
  int i, c;
  while((c = getchar()) != EOF) {
     for (i=1; s[i] && s[i]!=c; i++); // 找错位之后的字符在常量表中的位置
     if (s[i]) putchar(s[i-1]); // 如果找到，则输出它的前一个字符
     else putchar(c);
  }
  return 0;
}
