// UVa1641/LA5910 ASCII Area
// Rujia Liu
#include<cstdio>
int main() {
  int h, w;
  char s[999];
  while(scanf("%d%d", &h, &w) == 2) {
    int ans = 0, c = 0;
    while(h--) {
      scanf("%s", s);
      int in = 0;
      for(int i = 0; i < w; i++) {
        if(s[i] == '/' || s[i] == '\\') { c++; in = !in; }
        else if(in) ans++;
      }
    }
    printf("%d\n", ans + c/2);
  }
  return 0;
}
