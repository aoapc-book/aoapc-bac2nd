// UVa210 Concurrency Simulator
// Rujia Liu
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

const int maxn = 1000;

deque<int> readyQ;
queue<int> blockQ;
int n, quantum, c[5], var[26], ip[maxn]; // ip[pid]是程序pid的当前行号。所有程序都存在prog数组，更类似真实的情况，代码也更短
bool locked;
char prog[maxn][10];

void run(int pid) {
  int q = quantum;
  while(q > 0) {
    char *p = prog[ip[pid]];
    switch(p[2]) {
      case '=':
        var[p[0] - 'a'] = isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
        q -= c[0];
        break;
      case 'i': // print
        printf("%d: %d\n", pid+1, var[p[6] - 'a']);
        q -= c[1];
        break;
      case 'c': // lock
        if(locked) { blockQ.push(pid); return; }
        locked = true;
        q -= c[2];
        break;
      case 'l': // unlock
        locked = false;
        if(!blockQ.empty()) {
          int pid2 = blockQ.front(); blockQ.pop();
          readyQ.push_front(pid2);
        }
        q -= c[3];
        break;
      case 'd': // end
        return;
    }
    ip[pid]++;
  }
  readyQ.push_back(pid);
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d %d %d %d %d %d\n", &n, &c[0], &c[1], &c[2], &c[3], &c[4], &quantum);
    memset(var, 0, sizeof(var));

    int line = 0;
    for(int i = 0; i < n; i++) {
      fgets(prog[line++], maxn, stdin);
      ip[i] = line - 1;
      while(prog[line - 1][2] != 'd')
        fgets(prog[line++], maxn, stdin);
      readyQ.push_back(i);
    }

    locked = false;
    while(!readyQ.empty()) {
      int pid = readyQ.front(); readyQ.pop_front();
      run(pid);
    }
    if(T) printf("\n");
  }
  return 0;
}
