#include<iostream>
using namespace std;

struct Point {
  int x, y;
//  Point(int x=0, int y=0):x(x),y(y) {}
  Point(int x=0, int y=0) { this->x = x; this->y = y; }
};

// 定义了+运算符之后，下面的sum模板函数就可以用于Point数组了！
Point operator + (const Point& A, const Point& B) {
  return Point(A.x+B.x, A.y+B.y);
}

ostream& operator << (ostream &out, const Point& p) {
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

/*
int sum(int* begin, int* end) {
  int *p = begin;
  int ans = 0;
  for(int *p = begin; p != end; p++)
    ans += *p;
  return ans;
}
*/

// 下面是模板函数sum，修改自上述int版的sum函数
template<typename T>
T sum(T* begin, T* end) {
  T *p = begin;
  T ans = 0;
  for(T *p = begin; p != end; p++)
    ans = ans + *p;
  return ans;
}

int main() {
  double a[] = {1.1, 2.2, 3.3, 4.4};
  cout << sum(a, a+4) << "\n";
  Point b[] = { Point(1,2), Point(3,4), Point(5,6), Point(7,8) };
  cout << sum(b, b+4) << "\n";
  return 0;
}
