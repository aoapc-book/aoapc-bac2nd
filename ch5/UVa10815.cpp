// UVa10815 Andy's First Dictionary
// Rujia Liu
// 题意：输入一个文本，找出所有不同的单词（连续字母序列），按字典序从小到大输出。单词不分大小写。
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

set<string> dict;
string s, buf;

int main() {
  while(cin >> s) {
    for(int i = 0; i < s.length(); i++)
      if(isalpha(s[i])) s[i] = tolower(s[i]); else s[i] = ' ';
    stringstream ss(s);
    while(ss >> buf) dict.insert(buf);
  }
  for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    cout << *it << "\n";
  return 0;
}
