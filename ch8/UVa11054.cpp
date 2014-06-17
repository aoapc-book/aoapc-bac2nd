// UVa11054 Wine trading in Gergovia
// Rujia Liu
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    long long ans = 0, a, last = 0;
    for(int i = 0; i < n; i++) {
      cin >> a;
      ans += abs(last);
      last += a;
    }
    cout << ans << "\n";
  }
  return 0;
}
