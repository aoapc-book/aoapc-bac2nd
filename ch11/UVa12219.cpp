// UVa12219 Common Subexpression Elimination
// Rujia Liu

#include<cstdio>
#include<string>
#include<map>
using namespace std;

const int maxn = 60000;
int T, kase, cnt;
char expr[maxn*5], *p;
int done[maxn]; // 该结点是否已输出

struct Node {
  string s;
  int hash, left, right;
  bool operator < (const Node& rhs) const {
    if(hash != rhs.hash) return hash < rhs.hash;
    if(left != rhs.left) return left < rhs.left;
    return right < rhs.right;
  }
} node[maxn];

map<Node,int> dict;

int parse() {
  int id = cnt++;
  Node& u = node[id];
  u.left = u.right = -1;
  u.s = "";
  u.hash = 0;
  while(isalpha(*p)) {
    u.hash = u.hash * 27 + *p - 'a' + 1;
    u.s.push_back(*p);
    p++;
  }
  if (*p == '(') { // (L,R)
    p++; u.left = parse(); p++; u.right = parse(); p++;
  }
  if (dict.count(u) != 0) {
    id--; cnt--;       
    return dict[u];
  }
  return dict[u] = id;
}

void print(int v) {
  if(done[v] == kase)
    printf("%d", v + 1);
  else {      
    done[v] = kase; // 常见小技巧，可以避免memset(done, 0, sizeof(done))
    printf("%s", node[v].s.c_str());
    if(node[v].left != -1) {
      putchar('(');
      print(node[v].left);
      putchar(',');
      print(node[v].right);
      putchar(')');
    }
  }  
}

int main() {
  scanf("%d", &T);
  for(kase = 1; kase <= T; kase++) {
    dict.clear();
    cnt = 0;
    scanf("%s", expr);
    p = expr;
    print(parse());
    putchar('\n');    
  }
  return 0;
}
