// UVa1347 Tour
// Rujia Liu
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 50 + 5;
double x[maxn], y[maxn], dist[maxn][maxn], d[maxn][maxn];

int main() {
  int n;
  while(scanf("%d", &n) == 1) {
    for(int i = 1; i <= n; i++)
      scanf("%lf%lf", &x[i], &y[i]);
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        dist[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));

    for(int i = n-1; i >= 2; i--)
      for(int j = 1; j < i; j++) {
        if(i == n-1) d[i][j] = dist[i][n] + dist[j][n]; // 边界
        else d[i][j] = min(dist[i][i+1] + d[i+1][j], dist[j][i+1] + d[i+1][i]);
      }
    printf("%.2lf\n", dist[1][2] + d[2][1]);
  }
  return 0;
}
