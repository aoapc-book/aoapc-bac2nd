// UVa1642 Magical GCD
// Rujia Liu
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;

struct Item {
  LL g; // gcd
  int p; // starting pos
  Item(LL g=0, int p=0):g(g),p(p){}
  bool operator < (const Item& rhs) const {
    return g < rhs.g || (g == rhs.g && p < rhs.p);
  }
};

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); }

const int maxn = 100000 + 5;

LL A[maxn];
int n;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &A[i]);
    vector<Item> items;
    LL ans = 0;
    for(int j = 0; j < n; j++) { // enumerate end pos
      items.push_back(Item(0, j));
      for(int k = 0; k < items.size(); k++)
        items[k].g = gcd(items[k].g, A[j]); // update items' gcd
      sort(items.begin(), items.end());

      // for each gcd, only keep smallest starting pos
      vector<Item> newitems;
      for(int k = 0; k < items.size(); k++)
        if(k == 0 || items[k].g != items[k-1].g) { // different gcd
          newitems.push_back(items[k]);
          ans = max(ans, items[k].g * (j - items[k].p + 1));
        }
      items = newitems;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
