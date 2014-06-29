// UVa12325 Zombie's Treasure Chest
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

int main(){
  int T;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; kase++) {
    int n, s1, v1, s2, v2;
    scanf("%d%d%d%d%d", &n, &s1, &v1, &s2, &v2);
    if(s1 > s2){
      swap(s1, s2);
      swap(v1, v2);
    }
    LL ans = 0;
    if(n / s2 >= 65536){ // both s1 and s2 are small
      for(LL i = 0; i <= s1; i++){
        ans = max(ans, v2*i + (n-s2*i)/s1*v1);
      }
      for(LL i = 0; i <= s2; i++){
        ans = max(ans, v1*i + (n-s1*i)/s2*v2);
      }
    }else{ // s2 is large
      for(LL i = 0; s2*i <= n; i++)
        ans = max(ans, v2*i + (n-s2*i)/s1*v1);
    }
    printf("Case #%d: %lld\n", kase, ans);
  }
  return 0;
}
