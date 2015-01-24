// UVa1672 Disjoint Regular Expressions
// Rujia Liu
//
// This is Problem 12-2 of <<Beginning Algorithm Contests>> 2nd edition
//
// This code is neither simplest nor most efficient, but it's easy to understand and fast enough.
// Algorithm implemented here: 
//   1. build epsilon-NFA from the regex
//   2. build NFA by removing epsilon from epsilon-NFA. Note that we did NOT optimize the epsilon-NFA as described in the book.
//   3. use BFS to find a common string of these two NFAs
// Attention: the output should NOT be empty so we used a little trick.
//
// Alternative algorithm: do BFS directly on epsilon-NFAs. 
// State is (s1,s2,b) where b=1 iff at least one non-epsilon transition is performed.
// However, this graph is now 0-1 weighted so we need to use deque (or two-phase BFS).
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cassert>
#define REP(i,n) for(int i = 0; i < (n); ++i)

using namespace std;

// Part I: Expression Parser
struct ExprNode {
  enum {A, STAR, OR, CONCAT};
  int type, val;
  ExprNode *l, *r;

  ExprNode(int type, ExprNode* l, ExprNode* r, int val = -1):type(type),l(l),r(r),val(val){}
  ~ExprNode() {
     if(l) delete l;
     if(r) delete r;
   }
};

struct Parser {  
  char* s;
  int p, n;

  void Skip(char c) { p++; } // for debug purpose

  // (u)*
  ExprNode* Item() {
    ExprNode* u;
    if(s[p] == '(') { Skip('('); u = Expr(); Skip(')'); }
    else u = new ExprNode(ExprNode::A, NULL, NULL, s[p++]);
    while(s[p] == '*') {
      Skip('*');
      u = new ExprNode(ExprNode::STAR, u, NULL);
    }
    return u;    
  }

  // u1u2u3...
  ExprNode* Concat() {
    ExprNode* u = Item();
    while(s[p] && s[p] != ')' && s[p] != '|')
      u = new ExprNode(ExprNode::CONCAT, u, Item());
    return u;
  }

  // u1|u2|u3
  ExprNode* Expr() {
    ExprNode* u = Concat();
    while(s[p] == '|') {
      Skip('|');
      u = new ExprNode(ExprNode::OR, u, Concat());
    }
    return u;
  }

  ExprNode* parse(char* str) {
    s = str;
    n = strlen(s);
    p = 0;
    return Expr();
  }
  
};

// Part II: NFA construction
const int maxs = 100 * 4 + 5;

struct NFA {
  int n; // number of states

  struct Transition {
    int ch, next;
    Transition(int ch = 0, int next = 0):ch(ch),next(next){}
    bool operator < (const Transition& rhs) const {
      if(ch != rhs.ch) return ch < rhs.ch;
      return next < rhs.next;
    }
  };
  vector<Transition> trans[maxs];

  void add(int s, int t, int c) {
    trans[s].push_back(Transition(c, t));
  }

  void process(ExprNode* u) {
    int st = n++; // state 'start'
    if(u->type == ExprNode::A) add(st, n, u->val);
    else if(u->type == ExprNode::STAR) {
      process(u->l);
      add(st, st+1, -1);
      add(st, n, -1);
      add(n-1, st, -1);
    }
    else if(u->type == ExprNode::OR) {
      process(u->l);
      int m = n;
      process(u->r);
      add(st, st+1, -1);
      add(st, m, -1);
      add(m-1, n, -1);
      add(n-1, n, -1);
    }
    else if(u->type == ExprNode::CONCAT) {
      add(st, st+1, -1);
      process(u->l);
      add(n-1, n, -1);
      process(u->r);
      add(n-1, n, -1);
    }
    n++; // state 'end'
  }

  void init(char* s) {
    Parser p;
    ExprNode* root = p.parse(s);
    n = 0;
    for(int i = 0; i < maxs; i++) {
      trans[i].clear();
    }
    process(root);
    delete root;
  }

  vector<int> ss; // starting states

  void remove_epsilon() {
    // find epsilon-closure for each state
    vector<int> reachable[maxs];
    int vis[maxs];
    for(int i = 0; i < n; i++) {
      reachable[i].clear();
      reachable[i].push_back(i);
      queue<int> q;
      q.push(i);
      memset(vis, 0, sizeof(vis));
      vis[i] = 1;
      while(!q.empty()) {
        int s = q.front(); q.pop();
        for(int j = 0; j < trans[s].size(); j++)
          if(trans[s][j].ch == -1) {
            int s2 = trans[s][j].next;
            if(!vis[s2]) {
              reachable[i].push_back(s2);
              vis[s2] = 1;
              q.push(s2);
            }
          }
      }
    }
    ss = reachable[0];

    // merge transitions
    for(int i = 0; i < n; i++) {
      set<Transition> tr;
      for(int j = 0; j < trans[i].size(); j++) {
        if(trans[i][j].ch == -1) continue;
        int s = trans[i][j].next;
        for(int k = 0; k < reachable[s].size(); k++)
          tr.insert(Transition(trans[i][j].ch, reachable[s][k]));
      }
      trans[i] = vector<Transition>(tr.begin(), tr.end());
    }
  }
};

// Part III: BFS to find the answer

const int maxn = 100 + 5;
const int maxq = 100 * 4 * 100 * 4 * 2 + 5; // case 26
char sa[maxn], sb[maxn];

struct State {
  int s1, s2, fa, ch;
} states[maxq];
int ns;

void print_solution(int s) {
  if(states[s].fa == -1) return;
  print_solution(states[s].fa);
  printf("%c", states[s].ch);
}

void solve(const NFA& A, const NFA& B) {
  queue<int> q;
  int vis[maxs][maxs];
  memset(vis, 0, sizeof(vis));
  ns = 0;
  REP(i, A.ss.size())
    REP(j, B.ss.size()) {
      int s1 = A.ss[i], s2 = B.ss[j];
      states[ns].s1 = s1;
      states[ns].s2 = s2;
      states[ns].fa = -1;
      q.push(ns++);
    }

  while(!q.empty()) {
    int s = q.front(); q.pop();
    int s1 = states[s].s1;
    int s2 = states[s].s2;
    if(s1 == A.n-1 && s2 == B.n-1 && states[s].fa != -1) {
      printf("Wrong\n");
      print_solution(s);
      printf("\n");
      return;
    }
    int n1 = A.trans[s1].size();
    int n2 = B.trans[s2].size();

    REP(i, n1) REP(j, n2)
      if(A.trans[s1][i].ch == B.trans[s2][j].ch) {
        int s1b = A.trans[s1][i].next;
        int s2b = B.trans[s2][j].next;
        int c = A.trans[s1][i].ch;
        if(vis[s1b][s2b]) continue;
        vis[s1b][s2b] = 1;
        states[ns].s1 = s1b;
        states[ns].s2 = s2b;
        states[ns].fa = s;
        states[ns].ch = c;
        q.push(ns++);
      }
  }
  printf("Correct\n");  
}

NFA A, B;
int main() {
  while(scanf("%s%s", sa, sb) == 2) {
    A.init(sa);
    B.init(sb);
    A.remove_epsilon();
    B.remove_epsilon();
    solve(A, B);
  }
  return 0;
}
