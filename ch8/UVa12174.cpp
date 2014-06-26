// UVa12174 Shuffle
// Rujia Liu
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 100000 + 5;
int s, n, x[maxn*3], cnt[maxn], ok[maxn*2];

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> s >> n;

    // add s "-1" to the left/right of orriginal sequence
    // so we don't have to worry about negative subscript or wrapping round
    fill(x, x+n+2*s, -1);
    for(int i = 0; i < n; i++) cin >> x[i+s];

    int tot = 0; // how many different integers in current sliding window
    fill(cnt+1, cnt+s+1, 0); // cnt[i] is the number of occurrence of i in the current sliding window
    fill(ok, ok+n+s+1, 0);   // ok[i] = 1 iff the i-th sliding window didn't have duplicate numbers

    // compute "ok" array
    for(int i = 0; i < n+s+1; i++) {
      if (tot == s) ok[i] = 1;              // complete window
      if (i < s && tot == i) ok[i] = 1;     // incomplete windows on the left side
      if (i > n && tot == n+s-i) ok[i] = 1; // incomplete windows on the right side

      // update cnt and tot for the next sliding window
      if (i == n+s) break; // no more sliding windows, so we stop here
      if (x[i] != -1 && --cnt[x[i]]==0) tot--; // remove the first one
      if (x[i+s] != -1 && cnt[x[i+s]]++==0) tot++; // add the next one
    }

    // check each possible answer
    int ans = 0;
    for(int i = 0; i < s; i++) {
      int valid = 1;
      for (int j = i; j < n+s+1; j += s)
        if(!ok[j]) valid = 0;;
      if(valid) ans++;
    }
    if(ans == n+1) ans = s; // special case
    cout << ans << "\n";
  }
  return 0;
}
