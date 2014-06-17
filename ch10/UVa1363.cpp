// UVa1363 Joseph's Problem
// Rujia Liu
#include<iostream>
#include<algorithm>
using namespace std;

// 首项为a，公差为-d，除了首项之外还有n项
// 末项为a-n*d，平均数为(2*a-n*d)/2
long long sum(int a, int d, int n) {
  return (long long)(2*a-n*d)*(n+1)/2;
}

int main() {
  int n, k;
  while(cin >> n >> k) {
    int i = 1;
    long long ans = 0;
    while(i <= n) {
      int q = k % i, p = k / i;
      int cnt = n - i; // 最多还有n - i项
      if(p > 0) cnt = min(cnt, q / p);
      ans += sum(q, p, cnt);
      i += cnt + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
