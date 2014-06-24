// UVa10618 Tango Tango Insurrection
// Rujia Liu
// Tricky case: .RDLU
// Answer: RLRLR (yes, you TURNED around!)
#include<cstdio>
#include<cstring>
#include<cassert>

const int UP = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;

const int maxn = 70 + 5;

// d[i][a][b][s] means the minimal future energy when you already tapped i notes
// your left foot at a, right foot at b, last foot is s
int d[maxn][4][4][3];

// if the optimal strategy is to move foot f(0~2) to position t, action=f*4+t
int action[maxn][4][4][3]; 

char seq[maxn], pos[256], footch[] = ".LR";

// energy needed to move a foot FOR THE SECOND TIME, from a to ta
int energy(int a, int ta) {
  if(a == ta) return 3;
  if(a + ta == 3) return 7; // across
  return 5; // adjacent
}

int energy(int i, int a, int b, int s, int f, int t, int& ta, int& tb) {
  ta = a; tb = b;
  if(f == 1) ta = t;
  else if(f == 2) tb = t;

  // check target arrows
  if(ta == tb) return -1;
  if(ta == RIGHT && tb == LEFT) return -1;
  if(a == RIGHT && tb != b) return -1; // you can't move you right foot before your left foot comes back
  if(b == LEFT  && ta != a) return -1;

  // compute energy
  int e;
  if(f == 0) e = 0; // no move
  else if(f != s) e = 1; // alternative foot, low energy
  else {
    if(f == 1) e = energy(a, ta);
    else e = energy(b, tb);
  }
  return e;
}

// update state (i,a,b,s). foot f is moved to t
void update(int i, int a, int b, int s, int f, int t) {
  int ta, tb;
  int e = energy(i, a, b, s, f, t, ta, tb);
  if(e < 0) return; // invalid

  int cost = d[i+1][ta][tb][f] + e;
  int& ans = d[i][a][b][s];
  if(cost < ans) {
    ans = cost;
    action[i][a][b][s] = f * 4 + t;
  }
}

int main() {
  pos['U'] = 0; pos['L'] = 1; pos['R'] = 2; pos['D'] = 3;

  while(scanf("%s", seq) == 1) {
    if(seq[0] == '#') break;
    int n = strlen(seq);
    memset(d, 0, sizeof(d));
    for(int i = n-1; i >= 0; i--)
      for(int a = 0; a < 4; a++)
        for(int b = 0; b < 4; b++) if(a != b)
          for(int s = 0; s < 3; s++) {
            d[i][a][b][s] = 10*n;
            if(seq[i] == '.') {
              update(i, a, b, s, 0, 0); // no move
              for(int t = 0; t < 4; t++) {
                update(i, a, b, s, 1, t); // move left foot
                update(i, a, b, s, 2, t); // move right foot
              }
            } else {
              update(i, a, b, s, 1, pos[seq[i]]); // move left foot
              update(i, a, b, s, 2, pos[seq[i]]); // move right foot
            }
          }

    // print solution
    int a = LEFT, b = RIGHT, s = 0; // d[0][1][2][0] is out answer
    for(int i = 0; i < n; i++) {
      int f = action[i][a][b][s] / 4;
      int t = action[i][a][b][s] % 4;
      printf("%c", footch[f]);
      s = f;
      if(f == 1) a = t;
      else if(f == 2) b = t;
    }
    printf("\n");
  }
  return 0;
}
