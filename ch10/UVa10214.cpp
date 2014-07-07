// UVa10214 Trees in a Wood
// Rujia Liu
// This problem asks for K/N, where N is the total number of trees in area |x|<=a, |y|<=b
// The answer converges to 6/pi^2, see the problem description
#include<cstdio>
#include<cmath>
using namespace std;

int phi(int n) {
  int m = (int)sqrt(n+0.5);
  int ans = n;
  for(int i = 2; i <= m; i++) if(n % i == 0) {
    ans = ans / i * (i-1);
    while(n % i == 0) n /= i;
  }
  if(n > 1) ans = ans / n * (n-1);
  return ans;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

long long f(int a, int b) {
  long long ans = 0; // only for 1<=x<=a, 1<=y<=b
  for(int x = 1; x <= a; x++) {
    int k = b/x;
    ans += phi(x) * k;
    for(int y = k*x+1; y <= b; y++)
      if(gcd(x, y) == 1) ans++;
  }
  return ans * 4 + 4;
}

int main() {
  int a, b;
  while(scanf("%d%d", &a, &b) == 2 && a) {
    long long K = f(a,b);
    long long N = (long long)(2*a+1) * (2*b+1) - 1;
    printf("%.7lf\n", (double)K / N);
  }
  return 0;
}
