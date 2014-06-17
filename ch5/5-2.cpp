#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  long long a, b;
  while(cin >> a >> b) {
    cout << min(a,b) << "\n";
  }
  return 0;
}
