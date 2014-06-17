#include<iostream>
using namespace std;

struct Point {
  int x, y;
  Point(int x=0, int y=0):x(x),y(y) {}
};

int main() {
  Point p1, p2;
  swap(p1, p2);
  return 0;
}
