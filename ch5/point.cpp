#include<iostream>
using namespace std;

struct Point {
  int x, y;
//  Point(int x=0, int y=0):x(x),y(y) {}
  Point(int x=0, int y=0) { this->x = x; this->y = y; }
};

Point operator + (const Point& A, const Point& B) {
  return Point(A.x+B.x, A.y+B.y);
}

ostream& operator << (ostream &out, const Point& p) {
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

int main() {
  Point a, b(1,2);
  a.x = 3;
  cout << a+b << "\n";
  return 0;
}
