// UVa1636/LA4596 Headshot
// Rujia Liu
#include<cstdio>
#include<cstring>
int main() {
  char s[120];
  while(scanf("%s", s) == 1) {
    int a = 0, b = 0, n = strlen(s);
    for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
        b++;
        if(s[(i+1)%n] == '0') a++;
      }
    }
    if(a*n == b*b) printf("EQUAL\n");
    else if(a*n > b*b) printf("SHOOT\n");
    else printf("ROTATE\n");
  }
  return 0;
}
