// 八数码，使用哈希表（竞赛中最常用）
// Rujia Liu

#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

typedef int State[9];
const int MAXSTATE = 1000000;
State st[MAXSTATE], goal;
int dist[MAXSTATE];

const int MAXHASHSIZE = 1000003;
int head[MAXHASHSIZE], next[MAXSTATE];
void init_lookup_table() { memset(head, 0, sizeof(head)); }
int hash(State& s) {
  int v = 0;
  for(int i = 0; i < 9; i++) v = v * 10 + s[i];
  return v % MAXHASHSIZE;
}
int try_to_insert(int s) {
  int h = hash(st[s]);
  int u = head[h];
  while(u) {
    if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
    u = next[u];
  }
  next[s] = head[h];
  head[h] = s;
  return 1;
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int bfs() {
  init_lookup_table();
  int front = 1, rear = 2;
  while(front < rear) {
    State& s = st[front];
    if(memcmp(goal, s, sizeof(s)) == 0) return front;
    int z;
    for(z = 0; z < 9; z++) if(!s[z]) break;
    int x = z/3, y = z%3;
    for(int d = 0; d < 4; d++) {
      int newx = x + dx[d];
      int newy = y + dy[d];
      int newz = newx * 3 + newy;
      if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
        State& t = st[rear];
        memcpy(&t, &s, sizeof(s));
        t[newz] = s[z];
        t[z] = s[newz];
        dist[rear] = dist[front] + 1;
        if(try_to_insert(rear)) rear++;
      }
    }
    front++;
  }
  return 0;
}

int main() {
  for(int i = 0; i < 9; i++)
    scanf("%d", &st[1][i]);
  for(int i = 0; i < 9; i++)
    scanf("%d", &goal[i]);
  int ans = bfs();
  if(ans > 0) printf("%d\n", dist[ans]);
  else printf("-1\n");
  return 0;
}
