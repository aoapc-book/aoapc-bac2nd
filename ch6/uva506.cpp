// UVa506 System Dependencies
// Rujia Liu
// 注意：显式安装的必须显式删除
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 10000;

int cnt = 0;
map<string, int> name2id;
string name[maxn];

vector<int> depend[maxn], depend2[maxn];
int status[maxn]; // 0-not installed, 1-explicitly installed, 2-implicitly installed
vector<int> installed;

int ID(const string& item) {
  if(!name2id.count(item)) {
    name[++cnt] = item;
    name2id[item] = cnt;
  }
  return name2id[item];
}

bool needed(int item) {
  for(int i = 0; i < depend2[item].size(); i++)
    if(status[depend2[item][i]]) return true;
  return false;
}

void install(int item, bool toplevel) {
  if(!status[item]) {
    for(int i = 0; i < depend[item].size(); i++)
      install(depend[item][i], false);
    cout << "   Installing " << name[item] << "\n";
    status[item] = toplevel ? 1 : 2;
    installed.push_back(item);
  }
}

void remove(int item, bool toplevel) {
  if((toplevel || status[item] == 2) && !needed(item)) {
    status[item] = 0;
    installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
    cout << "   Removing " << name[item] << "\n";
    for(int i = 0; i < depend[item].size(); i++)
      remove(depend[item][i], false);
  }
}

// 按照安装顺序输出
void list() {
  for(int i = 0; i < installed.size(); i++)
    cout << "   " << name[installed[i]] << "\n";
}

int main() {
  string line, cmd;
  memset(status, 0, sizeof(status));
  while(getline(cin, line)) {
    cout << line << "\n";
    stringstream ss(line);
    ss >> cmd;
    if(cmd[0] == 'E') break;    
    string item1, item2;
    if(cmd[0] == 'L') list();
    else {
      ss >> item1;
      int i1 = ID(item1);
      if(cmd[0] == 'D') {
        while(ss >> item2) {
          int i2 = ID(item2);
          depend[i1].push_back(i2);
          depend2[i2].push_back(i1);
        }
      }
      else if(cmd[0] == 'I') {
        if(status[i1]) cout << "   " << item1 << " is already installed.\n";
        else install(i1, true);
      }
      else {
        if(!status[i1]) cout << "   " << item1 << " is not installed.\n";
        else if(needed(i1)) cout << "   " << item1 << " is still needed.\n";
        else remove(i1, true);
      }
    }
  }
  return 0;
}
