#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define N 100000000

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

LL s2i(string s) {
  stringstream ss;
  ss << s;
  LL res;
  ss >> res;
  return res;
}

string i2s(LL n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

vector<int> mm[6];

void init() {
  for (int i = 1; ; ++i) {
    int t = i * (i + 1) / 2;
    if (t > 9999) break;
    if (t >= 1000) mm[0].push_back(t);
  }

  for (int i = 1; ; ++i) {
    int t = i * i;
    if (t > 9999) break;
    if (t >= 1000) mm[1].push_back(t);
  }

  for (int i = 1; ; ++i) {
    int t = i * (3 * i - 1) / 2;
    if (t > 9999) break;
    if (t >= 1000) mm[2].push_back(t);
  }

  for (int i = 1; ; ++i) {
    int t = i * (2 * i - 1);
    if (t > 9999) break;
    if (t >= 1000) mm[3].push_back(t);
  }

  for (int i = 1; ; ++i) {
    int t = i * (5 * i - 3) / 2;
    if (t > 9999) break;
    if (t >= 1000) mm[4].push_back(t);
  }

  for (int i = 1; ; ++i) {
    int t = i * (3 * i - 2);
    if (t > 9999) break;
    if (t >= 1000) mm[5].push_back(t);
  }
}

int vv[6];
int dd[6];
int flag;

void dfs(int idx) {
  if (idx == 6) {
    if (dd[5] % 100 == dd[0] / 100) {
      int ret = 0;
      REP(i,6) {
	cout << dd[i] << endl;
	ret += dd[i];
      }
      cout << ret << endl;
      flag = true;
      return;
    }
  }

  if (flag) return;

  FOR(i,1,5) {
    if (vv[i] == 1) continue;
    REP(j,mm[i].size()) {
      if (dd[idx - 1] % 100 != mm[i][j] / 100) continue;
      vv[i] = 1;
      dd[idx] = mm[i][j];
      dfs(idx + 1);
      vv[i] = 0;
    }
  }
}

void run() {
  init();
  /*REP(i,6) {
    REP(j,mm[i].size()) cout << mm[i][j] << " ";
    cout << "-------------------" << endl << mm[i].size() << endl;
    }*/
  flag = false;
  memset(vv, 0, sizeof(vv));
  REP(i,mm[0].size()) {
    dd[0] = mm[0][i];
    dfs(1);
    if (flag) break;
  }
}

int main () {
  run();
  return 0;
}
