// UVa12627 Erratic Expansion
// Rujia Liu
#include<iostream>
using namespace std;

// how many red balloons after k hours
long long c(int i) {
  return i == 0 ? 1 : c(i-1)*3;
}

// how many red balloons in the first i rows, after k hours
long long f(int k, int i) {
  if(i == 0) return 0;
  if(k == 0) return 1;

  int k2 = 1 << (k-1);
  if(i >= k2) return f(k-1, i-k2) + c(k-1)*2;
  else return f(k-1, i) * 2;
}

// how many red balloons in the last i rows, after k hours
long long g(int k, int i) {
  if(i == 0) return 0;
  if(k == 0) return 1;

  int k2 = 1 << (k-1);
  if(i >= k2) return g(k-1, i-k2) + c(k-1);
  else return g(k-1,i);
}

int main() {
  int T, k, a, b;
  cin >> T;
  for(int kase = 1; kase <= T; kase++) {
    cin >> k >> a >> b;
    cout << "Case " << kase << ": " << f(k, b) - f(k, a-1) << "\n";
  }
  return 0;
}
