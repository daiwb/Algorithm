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

int doit(int n) {
  int n2 = n * n;
  int a = n - 1, b = n + 1;
  int ta = a, tb = b;
  int ret = (ta + tb) % n2;
  map<pair<int, int>, int> mm;
  map<pair<int, int>, int>::iterator itr;
  while (true) {
    itr = mm.find(make_pair(ta, tb));
    if (itr != mm.end()) break;
    mm[make_pair(ta, tb)] = 1;
    ret = max(ret, (ta + tb) % n2);
    ta = ta * a % n2;
    tb = tb * b % n2;
  }
  return ret;
}

void run() {
  int res = 0;
  FOR(a,3,1000) {
    int t = doit(a);
    //cout << a << " " << t << endl;
    res += t;
  }
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
