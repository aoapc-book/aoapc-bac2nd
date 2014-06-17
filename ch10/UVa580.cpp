// UVa580 Critical Mass
// Rujia Liu
#include<iostream>
using namespace std;

int f[31], g[31];

int main() {
  f[0] = f[1] = f[2] = 0;
  g[0] = 1; g[1] = 2; g[2] = 4;
  for(int n = 3; n <= 30; n++) {
    f[n] = 1 << (n-3);
    for(int i = 2; i <= n-2; i++)
      f[n] += g[i-2] * (1 << (n-i-2));
    g[n] = (1<<n) - f[n];
  }
  int n;
  while(cin >> n && n)
    cout << f[n] << "\n";
  return 0;
}
