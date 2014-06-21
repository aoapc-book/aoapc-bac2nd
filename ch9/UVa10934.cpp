// UVa10934 Dropping water balloons
// Rujia Liu
#include<iostream>
#include<cstring>
using namespace std;

const int maxk = 100;
const int maxa = 63;

unsigned long long d[maxk+1][maxa+1];

int main() {
  memset(d, 0, sizeof(d));
  for(int i = 1; i <= maxk; i++)
    for(int j = 1; j <= maxa; j++)
      d[i][j] = d[i-1][j-1] + 1 + d[i][j-1];

  int k;
  unsigned long long n;
  while(cin >> k >> n && k) {
    int ans = -1;
    for(int i = 1; i <= maxa; i++)
      if(d[k][i] >= n) { ans = i; break; }
    if(ans < 0) cout << "More than " << maxa << " trials needed.\n";
    else cout << ans << "\n";
  }
  return 0;
}
