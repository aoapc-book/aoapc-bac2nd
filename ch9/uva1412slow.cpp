// UVa1412 Fund Management
// 本程序会超时，只是用来示范用编码/解码的方法编写复杂状态动态规划的方法
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const double INF = 1e30;
const int maxn = 8;
const int maxm = 100 + 5;

map<int, double> d[maxm];
map<int, int> opt[maxm], prev[maxm];
int m, n, s[maxn], k[maxn], kk;
double c, price[maxn][maxm];
char name[maxn][10];

int encode(int* portfolio) {
  int h = 0;
  for(int i = 0; i < n; i++) h = h * 9 + portfolio[i];
  return h;
}

int decode(int h, int* portfolio) {
  int totlot = 0;
  for(int i = n-1; i >= 0; i--) {
    portfolio[i] = h % 9;
    totlot += portfolio[i];
    h /= 9;
  }
  return totlot;
}

void update(int oldh, int day, int h, double v, int o) {
  if(d[day].count(h) == 0 || v > d[day][h]) {
    d[day][h] = v;
    opt[day][h] = o;
    prev[day][h] = oldh;
  }
}

double dp() {
  int portfolio[maxn];
  d[0][0] = c;
  for(int day = 0; day < m; day++)
    for(map<int, double>::iterator it = d[day].begin(); it != d[day].end(); it++) {
      int h = it->first;
      double v = it->second;
      int totlot = decode(h, portfolio);

      update(h, day+1, h, v, 0); // HOLD
      for(int i = 0; i < n; i++) {
        if(portfolio[i] < k[i] && totlot < kk && v >= price[i][day] - 1e-3) {
          portfolio[i]++;
          update(h, day+1, encode(portfolio), v - price[i][day], i+1); // BUY
          portfolio[i]--;
        }
        if(portfolio[i] > 0) {
          portfolio[i]--;
          update(h, day+1, encode(portfolio), v + price[i][day], -i-1); // SELL
          portfolio[i]++;
        }
      }
    }
  return d[m][0];
}

void print_ans(int day, int h) {
  if(day == 0) return;
  print_ans(day-1, prev[day][h]);
  if(opt[day][h] == 0) printf("HOLD\n");
  else if(opt[day][h] > 0) printf("BUY %s\n", name[opt[day][h]-1]);
  else printf("SELL %s\n", name[-opt[day][h]-1]);
}

int main() {
  int kase = 0;
  while(scanf("%lf%d%d%d", &c, &m, &n, &kk) == 4) {
    if(kase++ > 0) printf("\n");
    for(int i = 0; i < n; i++) {
      scanf("%s%d%d", name[i], &s[i], &k[i]);
      for(int j = 0; j < m; j++) { scanf("%lf", &price[i][j]); price[i][j] *= s[i]; }
    }
    for(int i = 0; i <= m; i++) { d[i].clear(); opt[i].clear(); prev[i].clear(); }

    double ans = dp();
    printf("%.2lf\n", ans);
    print_ans(m, 0);
  }
  return 0;
}
