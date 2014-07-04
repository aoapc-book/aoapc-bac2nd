// UVa1228 Integer Transmission
// Rujia Liu
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 64;

int n, d, K[maxn];
unsigned long long f[maxn+1][maxn+1];

int zcnt = 0, ocnt = 0;
int Z[maxn], O[maxn]; // z[i] is the i-th zero from left (0-based)

// now we received i zeros and j ones. Can we receive another zero at the next time?
bool can_receive_zero(int i, int j) {
  return i+1 <= zcnt && (j == ocnt || O[j]+d >= Z[i]);
}

bool can_receive_one(int i, int j) {
  return j+1 <= ocnt && (i == zcnt || Z[i]+d >= O[j]);
}

unsigned long long minv, maxv;

void greedy() {
  minv = maxv = 0;
  int i = 0, j = 0;
  while(i < zcnt || j < ocnt) {
    if(can_receive_zero(i, j)) { i++; minv = minv * 2; }
    else { j++; minv = minv * 2 + 1; }
  }
  i = j = 0;
  while(i < zcnt || j < ocnt) {
    if(can_receive_one(i, j)) { j++; maxv = maxv * 2 + 1; }
    else { i++; maxv = maxv * 2; }
  }
}

void solve() {
  // compute Z and O
  ocnt = zcnt = 0;
  for(int i = 0; i < n; i++)
    if(K[i] == 1) O[ocnt++] = i;
    else Z[zcnt++] = i;

  // greedy to get minv, maxv
  greedy();
  
  // dp
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for(int i = 0; i <= zcnt; i++)
    for(int j = 0; j <= ocnt; j++) {
      if(can_receive_zero(i, j)) f[i+1][j] += f[i][j];
      if(can_receive_one(i, j)) f[i][j+1] += f[i][j];
    }
  cout << f[zcnt][ocnt] << " " << minv << " " << maxv << "\n";
}

int main() {
  int kase = 0;
  unsigned long long k;
  while(cin >> n >> d >> k) {
    for(int i = 0; i < n; i++) {
      K[n-i-1] = k % 2; k /= 2;
    }
    cout << "Case " << ++kase << ": ";
    solve();
  }
  return 0;
}
