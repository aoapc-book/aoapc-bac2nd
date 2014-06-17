// UVa10288 Coupons
// Rujia Liu
#include<iostream>
#include<sstream>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
  if(!b) return a;
  return gcd(b, a%b);
}

LL lcm(LL a, LL b) {
  return a / gcd(a, b) * b;
}

int LL_len(LL x) {
  stringstream ss;
  ss << x;
  return ss.str().length();
}

void print_chars(int cnt, char ch) {
  while(cnt--) cout << ch;
}

void output(LL a, LL b, LL c) {
  if(b == 0) cout << a << "\n";
  else {
    int L1 = LL_len(a);
    print_chars(L1+1, ' '); cout << b << "\n";
    cout << a << " "; print_chars(LL_len(c), '-'); cout << "\n";
    print_chars(L1+1, ' '); cout << c << "\n";
  }
}

int main() {
  int n;
  while(cin >> n && n) {
    if(n == 1) { output(1, 0, 0); continue; }
    LL x = 1;
    for(int i = 2; i <= n-1; i++)
      x = lcm(x, i);

    // b/c = 1/(n-1) + ... + 1/2
    LL c = x, b = 0;
    for(int i = 2; i <= n-1; i++)
      b += x / i;
    b *= n;
    LL g = gcd(b, c);
    b /= g; c /= g;

    // ans = a + b/c
    LL a = 1 + n + b / c;
    b %= c;
    output(a, b, c);
  }
  return 0;
}
