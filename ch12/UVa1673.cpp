// UVa1673 str2int
// Rujia Liu
//
// This is Problem 12-3 of <<Beginning Algorithm Contests>> 2nd edition
//
// Note that we're using the "big string method", as explained in the book.
// It's slightly less efficient than the official "multiple string DAWG" because we need to explicitly store '$' edges.
// However, it's conceptually cleaner, and easier to understand.
#include <cstdio>
#include <cstring>
using namespace std;

const int maxc = 11; // 10 digits and '$'
const int maxn = 100000 + 10;

struct DAWG {
  struct Node {
    Node *fa, *next[maxc];
    int len;
    int id, pos;
    Node(){}
    Node(int len):fa(0),len(len){
      memset(next, 0, sizeof(next));
    }
  };

  Node node[maxn*2], *root, *last;
  int tot;

  Node *newnode(const Node& u) {
    node[tot] = u;
    node[tot].id = tot;
    return &node[tot++];
  }
  Node* newnode(int len) { return newnode(Node(len)); }
  Node* newnode(Node *p) { return newnode(*p); }

  void init() {
    tot = 0;
    root = last = newnode(0);
    node[0].pos = 0;
  }

  void add(int x,int len) {
    Node *p = last, *np = newnode(p->len + 1);
    np->pos = len;
    last = np;
    for(; p && !p->next[x];p = p->fa)
        p->next[x] = np;
    if(!p) { np->fa = root; return; }

    Node *q = p->next[x];
    if(q->len == p->len + 1) { np->fa = q; return; }

    Node *nq = newnode(q);
    nq->len = p->len + 1;
    q->fa = nq;
    np->fa = nq;
    for(; p && p->next[x] == q; p = p->fa)
        p->next[x] = nq;
  }
};


/////// problem related

const int MOD = 2012;

char s[maxn];
int topo[maxn*2], topocnt[maxn*2], sum[maxn*2], cnt[maxn*2];
DAWG g;

int main() {
  int n;
  while(scanf("%d", &n) == 1) {
    g.init();
    int totlen = 0;
    for(int i = 0; i < n; i++) {
      scanf("%s", s);
      int len = strlen(s);
      if(i > 0) g.add(10, ++totlen); // $
      for(int j = 0; j < len; j++) {
        g.add(s[j] - '0', ++totlen); // regular edges
      }
    }

    // topology sort
    for(int i = 0; i <= totlen; i++)
      topocnt[i] = 0;
    for(int i = 0; i < g.tot; i++)
      topocnt[g.node[i].len]++;
    for(int i = 1; i <= totlen; i++)
      topocnt[i] += topocnt[i-1];
    for(int i = 0; i < g.tot; i++)
      topo[--topocnt[g.node[i].len]] = i;

    int ans = 0;
    for(int i = 0; i < g.tot; i++)
      cnt[i] = sum[i] = 0;
    cnt[0] = 1;
    for(int i = 0; i < g.tot; i++) {
      int fa = topo[i];
      DAWG::Node* u = &g.node[fa];
      for(int j = 0; j < 10; j++) {
        if(i == 0 && j == 0) continue;
        if(u->next[j]) {
          int son = u->next[j]->id;
          cnt[son] = (cnt[son] + cnt[fa]) % MOD;
          sum[son] = (sum[son] + sum[fa]*10 + cnt[fa]*j) % MOD;
        }
      }
      ans = (ans + sum[fa]) % MOD;
    }
    printf("%d\n", ans);
  }
  return 0;
}
