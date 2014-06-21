// UVa1625 Color Length
// Rujia Liu

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 5000 + 5;
const int INF = 1000000000;

char p[maxn], q[maxn]; // starts from position 1
int sp[26], sq[26], ep[26], eq[26]; // sp[i] start positions of character i in p
int d[2][maxn], c[2][maxn]; // c[i][j]: how many "incomplete" colors in the mixed sequence

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%s%s", p+1, q+1);

    int n = strlen(p+1);
    int m = strlen(q+1);
    for(int i = 1; i <= n; i++) p[i] -= 'A';
    for(int i = 1; i <= m; i++) q[i] -= 'A';

    // calculate s and e
    for(int i = 0; i < 26; i++) { sp[i] = sq[i] = INF; ep[i] = eq[i] = 0; }
    for(int i = 1; i <= n; i++) {
      sp[p[i]] = min(sp[p[i]], i);
      ep[p[i]] = i;
    }
    for(int i = 1; i <= m; i++) {
      sq[q[i]] = min(sq[q[i]], i);
      eq[q[i]] = i;
    }

    // dp
    int t = 0;
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= m; j++){
        if(!i && !j) continue;

        // calculate d
        int v1 = INF, v2 = INF;
        if(i) v1 = d[t^1][j] + c[t^1][j]; // remove from p
        if(j) v2 = d[t][j - 1] + c[t][j - 1]; // remove from q
        d[t][j] = min(v1, v2);

        // calculate c
        if(i) {
          c[t][j] = c[t^1][j];
          if(sp[p[i]] == i && sq[p[i]] > j) c[t][j]++;
          if(ep[p[i]] == i && eq[p[i]] <= j) c[t][j]--;
        } else if(j) {
          c[t][j] = c[t][j - 1];
          if(sq[q[j]] == j && sp[q[j]] > i) c[t][j]++;
          if(eq[q[j]] == j && ep[q[j]] <= i) c[t][j]--;
        }
      }
      t ^= 1;
    }
    printf("%d\n", d[t^1][m]);
  }
  return 0;
}
