// UVa400 Unix ls
// Rujia Liu
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxcol = 60;
const int maxn = 100 + 5;
string filenames[maxn];

// 输出字符串s，长度不足len时补字符extra
void print(const string& s, int len, char extra) {
  cout << s;
  for(int i = 0; i < len-s.length(); i++)
    cout << extra;
}

int main() {
  int n;
  while(cin >> n) {
    int M = 0;
    for(int i = 0; i < n; i++) {
      cin >> filenames[i];
      M = max(M, (int)filenames[i].length());
    }
    // 计算列数cols和行数rows
    int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
    print("", 60, '-');
    cout << "\n";
    sort(filenames, filenames+n);
    for(int r = 0; r < rows; r++) {
      for(int c = 0; c < cols; c++) {
        int idx = c * rows + r;
        if(idx < n) print(filenames[idx], c == cols-1 ? M : M+2, ' ');
      }
      cout << "\n";
    }
  }
  return 0;
}
