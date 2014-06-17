// UVa11971 Polygon
// Rujia Liu
#include<iostream>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
  return b == 0 ? a : gcd(b, a%b);
}

void reduce(LL& a, LL& b) {
  LL g = gcd(a, b);
  a /= g; b /= g;
}

int main() {
  int T, n, k;
  cin >> T;
  for(int kase = 1; kase <= T; kase++) {
    cin >> n >> k;
    // 组不成的概率为(k+1)/2^k
    LL b = 1LL << k;
    LL a = b - k - 1;
    reduce(a, b);
    cout << "Case #" << kase << ": " << a << "/" << b << endl;
  }
  return 0;
}
