// UVa1279 Asteroid Rangers
// Rujia Liu
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 50 + 5;
const int maxks = maxn * (maxn+1) / 2;
const double eps = 1e-8;

int n, nks;

// event
struct Event {
  double t;
  int newks, oldks; // After event, newks will be smaller than oldks
  Event(double t=0, int newks=0, int oldks=0) : t(t), newks(newks), oldks(oldks) {}
  bool operator < (const Event& rhs) const {
    return t - rhs.t < 0;
  }
};
vector <Event> events;

struct KineticPoint {
  double x, y, z; // initial position
  double dx, dy, dz; // velocity
  void read() {
    scanf("%lf%lf%lf%lf%lf%lf", &x, &y, &z, &dx, &dy, &dz);
  }
} kp[maxn];

struct KineticSegment {
  double a, b, c; // length is at^2+bt+c
  int u, v; // end point IDs
  bool operator < (const KineticSegment& rhs) const { // compare initial length
    return c - rhs.c < 0;
  }
} ks[maxks];

inline double sqr(double x) { return x * x; }

// union-find
int pa[maxn];

void init_ufset() { for(int i = 0; i < n; i++) pa[i] = i; }
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; }

void make_segments() {
  nks = 0;
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++) {
      // the square distance between point i and point j is sum{((kp[i].dx-kp[j].dx) * t + (kp[i].x-kp[j].x))^2}
      // which can be re-written to at^2+bt+c. a>0, c>0
      ks[nks].a = sqr(kp[i].dx-kp[j].dx) + sqr(kp[i].dy-kp[j].dy) + sqr(kp[i].dz-kp[j].dz);
      ks[nks].b = 2*((kp[i].dx-kp[j].dx)*(kp[i].x-kp[j].x) + (kp[i].dy-kp[j].dy)*(kp[i].y-kp[j].y) + (kp[i].dz-kp[j].dz)*(kp[i].z-kp[j].z));
      ks[nks].c = sqr(kp[i].x-kp[j].x) + sqr(kp[i].y-kp[j].y) + sqr(kp[i].z-kp[j].z);
      ks[nks].u = i;
      ks[nks].v = j;
      nks++;
    }
  sort(ks, ks + nks);
}

void make_events() {
  events.clear();
  for(int i = 0; i < nks; i++)
    for(int j = i+1; j < nks; j++) {
      // when segment i's length is equal to segment j?
      int s1 = i, s2 = j; 
      if (ks[s1].a - ks[s2].a < 0) s1 = j, s2 = i; // s1 is more steep (bigger a value)

      double a = ks[s1].a - ks[s2].a;
      double b = ks[s1].b - ks[s2].b;
      double c = ks[s1].c - ks[s2].c;
      if(fabs(a) < eps) { // bt + c = 0
        if (fabs(b) < eps) continue; // no solution
        if (b > 0) { swap(s1, s2); b = -b; c = -c; } // bt + c = 0, b < 0
        if (c > 0) events.push_back(Event(-c / b, s1, s2)); // t > 0
        continue;
      }
      double delta = b * b - 4 * a * c;
      if (delta < eps) continue; // no solution
      delta = sqrt(delta);
      double t1 = -(b + delta) / (2 * a); // solution 1
      double t2 = (delta - b) / (2 * a); // solution 2
      if (t1 > 0) events.push_back(Event(t1, s1, s2)); // steep one will be smaller
      if (t2 > 0) events.push_back(Event(t2, s2, s1)); // flat one will be smaller
    }
  sort(events.begin(), events.end());
}

int solve() {
  int pos[maxks]; // pos[i] is the index of i-th segment in the MST. 0 means "not in MST"
  int e[maxn];    // e[i] (i > 0) is the i-th edge in current MST. pos[e[i]] = i

  // initial MST
  init_ufset();
  for(int i = 0; i < nks; i++) pos[i] = 0;
  int idx = 0;
  for(int i = 0; i < nks; i++) {
    int u = findset(ks[i].u), v = findset(ks[i].v);
    if (u != v) {
      e[pos[i] = ++idx] = i; 
      pa[u] = v;
    }
    if(idx == n-1) break;
  }

  int ans = 1;
  for(int i = 0; i < events.size(); i++) {
    if(pos[events[i].oldks] && (!pos[events[i].newks])) {
      init_ufset();
      int oldpos = pos[events[i].oldks];
      for(int j = 1; j < n; j++)
        if (j != oldpos) {
          int u = findset(ks[e[j]].u), v = findset(ks[e[j]].v);
          if(u != v) pa[u] = v;
        }
      int u = findset(ks[events[i].newks].u), v = findset(ks[events[i].newks].v);
      if(u != v) {
        // new MST found! now replace oldks with newks
        ans++;
        pos[events[i].newks] = oldpos;
        e[oldpos] = events[i].newks;
        pos[events[i].oldks] = 0;
      }
    }
  }
  return ans;
}

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1) {
    for(int i = 0; i < n; i++) kp[i].read();
    make_segments();
    make_events();
    int ans = solve();
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}
