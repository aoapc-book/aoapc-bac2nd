#include<iostream>
using namespace std;

template <typename T>
struct Point {
  T x, y;
  Point(T x=0, T y=0):x(x),y(y) {}
};

template <typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B) {
  return Point<T>(A.x+B.x, A.y+B.y);
}

template <typename T>
ostream& operator << (ostream &out, const Point<T>& p) {
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

int main() {
  Point<int> a(1,2), b(3,4);
  Point<double> c(1.1,2.2), d(3.3,4.4);
  cout << a+b << " " << c+d << "\n";
  return 0;
}
