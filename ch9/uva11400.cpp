// UVa11400 Lighting System Design
// Rujia Liu
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;

struct Lamp {
  int v, k, c, l;
  bool operator < (const Lamp& rhs) const {
    return v < rhs.v;
  }
} lamp[maxn];

int n, s[maxn], d[maxn];

int main() {
  while(cin >> n && n) {
    for(int i = 1; i <= n; i++)
      cin >> lamp[i].v >> lamp[i].k >> lamp[i].c >> lamp[i].l;
    sort(lamp+1, lamp+n+1);
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = s[i-1] + lamp[i].l;
    d[0] = 0;
    for(int i = 1; i <= n; i++) {
      d[i] = s[i] * lamp[i].c + lamp[i].k; // 前i个灯泡全买类型i
      for(int j = 1; j <= i; j++)
        d[i] = min(d[i], d[j] + (s[i] - s[j]) * lamp[i].c + lamp[i].k);
    }
    cout << d[n] << "\n";
  }
  return 0;
}
