// UVa1605 Building for UN
// Rujia Liu
#include<cstdio>
using namespace std;

char country(int i) {
  if(i < 26) return 'A' + i;
  return 'a' + i - 26;
}

int main() {
  int n;
  while(scanf("%d", &n) == 1) {
    printf("2 %d %d\n", n, n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) printf("%c", country(i));
      printf("\n");
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) printf("%c", country(j));
      printf("\n");
    }
  }
  return 0;
}
