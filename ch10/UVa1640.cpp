// UVa1640 The Counting Problem
// Rujia Liu
// The meaning of f is slightly different from the book
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

// cnt[i] is the number of occurrence of EVERY digit, among all i-digit numbers (leading zeros ALLOWED)
// for examples, there are 1000 3-digit numbers, each digit 0~9 has occurred 300 times, so cnt[3] = 300
int pow10[10], cnt[10];

// how many times digit d occurred in 0~n-1
// numbers in 0~4567 can be divided into the following patterns:
// fewer digits   : *, n*, n** (n means non-zero digit)
// smaller digit 0: 1***, 2***, 3***
// smaller digit 1: 40**, 41**, 42**, 43**, 44**
// smaller digit 2: 450*, 451*, ...
int f(int d, int n) {
  char s[10];
  sprintf(s, "%d", n);
  int len = strlen(s);
  int ans = 0;

  // fewer digits
  for(int i = 1; i < len; i++) {
    if(i == 1) ans++; // single digit
    else {
      ans += 9 * cnt[i-1];  // leading with another digit
      if(d > 0) ans += pow10[i-1]; // leading with digit d
    }
  }

  int pre[10]; // pre[i] is the occurrence of digit d in s[0~i]
  for(int i = 0; i < len; i++) {
    pre[i] = (s[i] - '0' == d ? 1 : 0);
    if(i > 0) pre[i] += pre[i-1];
  }

  for(int i = 0; i < len; i++) {
    // smaller digit i
    int maxd = s[i] - '0' - 1;
    int mind = 0;
    if(i == 0 && len > 1) mind = 1; // no leading zeros allowed
    for(int digit = mind; digit <= maxd; digit++) {
      ans += cnt[len-i-1];
      if(i > 0) ans += pre[i-1] * pow10[len-i-1];
      if(digit == d) ans += pow10[len-i-1];
    }
  }
  return ans;
}

int main() {
  pow10[0] = 1;
  for(int i = 1; i <= 8; i++) {
    pow10[i] = pow10[i-1] * 10;
    cnt[i] = pow10[i-1] * i;
  }

  int a, b;
  while(scanf("%d%d", &a, &b) == 2 && a && b) {
    if(a > b) swap(a, b);
    for(int d = 0; d < 10; d++) {
      if(d) printf(" ");
      printf("%d", f(d, b+1) - f(d, a));
    }
    printf("\n");
  }
  return 0;
}
