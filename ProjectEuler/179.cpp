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

#define MAXN 10000000

int mm[MAXN + 5];

void run() {
  FOR(i,2,MAXN-1) mm[i] = 1;
  FOR(i,2,MAXN-1) {
    int t = i;
    while (true) {
      mm[t] += 1;
      t += i;
      if (t >= MAXN) break;
    }
  }
  int res = 0;
  FOR(i,2,MAXN-1) {
    if (mm[i] == mm[i + 1]) ++res;
  }
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
