// UVa1606 Amphiphilic Carbon Molecules
// Rujia Liu
// To make life a bit easier, we change each color 1 point into color 0.
// Then we only need to find an angle interval with most points. See code for details.
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;

struct Point {
  int x, y;
  double rad; // with respect to current point
  bool operator<(const Point &rhs) const {
    return rad < rhs.rad;
  }
}op[maxn], p[maxn];

int n, color[maxn];

// from O-A to O-B, is it a left turn?
bool Left(Point A, Point B) {
  return A.x * B.y - A.y * B.x >= 0;
}

int solve() {
  if(n <= 2) return 2;
  int ans = 0;

  // pivot point
  for(int i = 0; i < n; i++) {
    int k = 0;

    // the list of other point, sorted in increasing order of rad
    for(int j = 0; j < n; j++)
      if(j != i) {
        p[k].x = op[j].x - op[i].x;
        p[k].y = op[j].y - op[i].y;
        if(color[j]) { p[k].x = -p[k].x; p[k].y = -p[k].y; }
        p[k].rad = atan2(p[k].y, p[k].x);
        k++;
      }
    sort(p, p+k);

    // sweeping. cnt is the number of points whose rad is between p[L] and p[R]
    int L = 0, R = 0, cnt = 2;
    while(L < k) {
      if(R == L) { R = (R+1)%k; cnt++; } // empty interval
      while(R != L && Left(p[L], p[R])) { R = (R+1)%k; cnt++; } // stop when [L,R] spans across > 180 degrees
      cnt--;
      L++;
      ans = max(ans, cnt);
    }
  }
  return ans;
}

int main() {
  while(scanf("%d", &n) == 1 && n) {
    for(int i = 0; i < n; i++)
      scanf("%d%d%d", &op[i].x, &op[i].y, &color[i]);
    printf("%d\n", solve());
  }
  return 0;
}
