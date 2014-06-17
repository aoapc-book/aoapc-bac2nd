#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

void fill_random_int(vector<int>& v, int cnt) {
  v.clear();
  for(int i = 0; i < cnt; i++)
    v.push_back(rand());
}

vector<int> fill_random_int(int cnt) {
  vector<int> v;
  for(int i = 0; i < cnt; i++)
    v.push_back(rand());
  return v;
}

void test_sort(vector<int>& v) {
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size()-1; i++)
    assert(v[i] <= v[i+1]);
}

int main()
{
  vector<int> v;
//  fill_random_int(v, 1000000);
  v = fill_random_int(1000000);
  test_sort(v);
  return 0;
}
