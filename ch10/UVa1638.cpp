// UVa1638/LA6117 Pole Arrangement
// Rujia Liu
#include<iostream>
using namespace std;

const int maxn = 20;
long long d[maxn+1][maxn+1][maxn+1];

int main() {
  d[1][1][1] = 1;
  for(int i = 2; i <= maxn; i++)
    for(int j = 1; j <= i; j++)
      for(int k = 1; k <= i; k++) {
        d[i][j][k] = d[i-1][j][k] * (i-2);
        if(j > 1) d[i][j][k] += d[i-1][j-1][k];
        if(k > 1) d[i][j][k] += d[i-1][j][k-1];
      }

  int T, n, L, R;
  cin >> T;
  while(T--) {
    cin >> n >> L >> R;
    cout << d[n][L][R] << "\n";
  }
  return 0;
}
