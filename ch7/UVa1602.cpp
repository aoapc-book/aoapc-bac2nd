// UVa1602 Lattice Animals
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

struct Cell {
  int x, y;
  Cell(int x=0, int y=0):x(x),y(y) {};
  bool operator < (const Cell& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
};

typedef set<Cell> Polyomino;

#define FOR_CELL(c, p) for(Polyomino::const_iterator c = (p).begin(); c != (p).end(); ++c)

inline Polyomino normalize(const Polyomino &p) {
  int minX = p.begin()->x, minY = p.begin()->y;
  FOR_CELL(c, p) {
    minX = min(minX, c->x);
    minY = min(minY, c->y);
  }
  Polyomino p2;    
  FOR_CELL(c, p)
    p2.insert(Cell(c->x - minX, c->y - minY));
  return p2;
}

inline Polyomino rotate(const Polyomino &p) {
  Polyomino p2;
  FOR_CELL(c, p)
    p2.insert(Cell(c->y, -c->x));
  return normalize(p2);
}

inline Polyomino flip(const Polyomino &p) {
  Polyomino p2;
  FOR_CELL(c, p)
    p2.insert(Cell(c->x, -c->y));
  return normalize(p2);
}

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
const int maxn = 10;

set<Polyomino> poly[maxn+1];
int ans[maxn+1][maxn+1][maxn+1];

// add a cell to p0 and check whether it's new. If so, add to the polyonimo set
void check_polyomino(const Polyomino& p0, const Cell& c) {
  Polyomino p = p0;
  p.insert(c);
  p = normalize(p);

  int n = p.size();
  for(int i = 0; i < 4; i++) {
    if(poly[n].count(p) != 0) return;
    p = rotate(p);
  }      
  p = flip(p);
  for(int i = 0; i < 4; i++) {
    if(poly[n].count(p) != 0) return;
    p = rotate(p);
  }
  poly[n].insert(p);
}

void generate() {
  Polyomino s;
  s.insert(Cell(0, 0));
  poly[1].insert(s);

  // generate
  for(int n = 2; n <= maxn; n++) {
    for(set<Polyomino>::iterator p = poly[n-1].begin(); p != poly[n-1].end(); ++p)
      FOR_CELL(c, *p)
        for(int dir = 0; dir < 4; dir++) {
          Cell newc(c->x + dx[dir], c->y + dy[dir]);
          if(p->count(newc) == 0) check_polyomino(*p, newc);
        }
  }

  // precompute answers
  for(int n = 1; n <= maxn; n++)
    for(int w = 1; w <= maxn; w++)
      for(int h = 1; h <= maxn; h++) {
        int cnt = 0;
        for(set<Polyomino>::iterator p = poly[n].begin(); p != poly[n].end(); ++p) {
          int maxX = 0, maxY = 0;
          FOR_CELL(c, *p) {
            maxX = max(maxX, c->x);
            maxY = max(maxY, c->y);
          }
          if(min(maxX, maxY) < min(h, w) && max(maxX, maxY) < max(h, w))
            ++cnt;
        } 
        ans[n][w][h] = cnt;
      }
}

int main() {
  generate();

  int n, w, h;
  while(scanf("%d%d%d", &n, &w, &h) == 3) {
    printf("%d\n", ans[n][w][h]);
  }
  return 0;
}
