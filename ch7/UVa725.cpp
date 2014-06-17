// UVa725 Division
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
  int n, kase = 0;
  char buf[99];
  while(scanf("%d", &n) == 1 && n) {
    int cnt = 0;
    if(kase++) printf("\n");
    for(int fghij = 1234; ; fghij++) {
      int abcde = fghij * n;
      sprintf(buf, "%05d%05d", abcde, fghij);
      if(strlen(buf) > 10) break;
      sort(buf, buf+10);
      bool ok = true;
      for(int i = 0; i < 10; i++)
        if(buf[i] != '0' + i) ok = false;
      if(ok) {
        cnt++;
        printf("%05d / %05d = %d\n", abcde, fghij, n);
      }
    }
    if(!cnt) printf("There are no solutions for %d.\n", n);
  }
  return 0;
}
