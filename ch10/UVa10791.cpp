// UVa10791 Minimum Sum LCM
// Rujia Liu
// 题意：输入整数n（1<=n<2^31），求至少两个正整数，使得它们的最小公倍数为n，且这些整数的和最小。输出最小的和。
// 算法：设唯一分解式n=a1^p1 * a2^p2...，不难发现每个a[i]^p[i]作为一个单独的整数时最优。
// 特例：n=1时答案为1+1=2。n只有一种因子时需要加个1。另外注意n=2^31-1时不要溢出
#include<cmath>
#include<iostream>
using namespace std;

int divide_all(int& n, int d) {
  int x = 1;
  while(n % d == 0) { n /= d; x *= d; }
  return x;
}

long long solve(int n) {
  if(n == 1) return 2;
  int m = floor(sqrt(n) + 0.5);
  long long ans = 0;
  int pf = 0; // 素因子(prime_factor)个数
  for(int i = 2; i < m; i++) {
    if(n % i == 0) { // 新的素因子
      pf++;
      ans += divide_all(n, i);
    }
  }
  if(n > 1) { pf++; ans += n; }
  if(pf <= 1) ans++;
  return ans;
}

int main() {
  int n, kase = 0;
  while(cin >> n && n)
    cout << "Case " << ++kase << ": " << solve(n) << "\n";
  return 0;
}

