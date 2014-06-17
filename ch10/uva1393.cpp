// UVa1393 Highway
// Rujia Liu
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 300;
int g[maxn+1][maxn+1];

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int n, m;
  for(int i = 1; i <= maxn; i++)
    for(int j = 1; j <= maxn; j++)
      g[i][j] = gcd(i, j);

  while(cin >> n >> m && n) {
    int ans = 0;
    for(int a = 1; a <= m; a++)
      for(int b = 1; b <= n; b++)
        if(g[a][b] == 1) {
          int c = max(0, m-2*a) * max(0, n-2*b);
          ans += (m-a)*(n-b) - c;
        }
    cout << ans*2 << "\n";
  }
  return 0;
}
