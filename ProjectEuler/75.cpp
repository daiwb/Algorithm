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

#define MAXN 2000000

int gcd(int a, int b) {
  while (true) {
    if (b == 0) break;
    a %= b;
    a ^= b ^= a ^= b;
  }
  return a;
}

map<int, set<pair<int, pair<int, int> > > > dic;

void run() {
  FOR(i,1,MAXN) dic[i] = set<pair<int, pair<int, int> > >();
  FOR(m,2,1000) {
    //cout << m << endl;
    FOR(n,1,m-1) {
      if (gcd(m, n) != 1) continue;
      int a = 2 * m * n;
      int b = m * m - n * n;
      int c = m * m + n * n;
      if (a > b) a ^= b ^= a ^= b;
      if (a > c) a ^= c ^= a ^= c;
      if (b > c) b ^= c ^= b ^= c;
      //cout << a << " " << b << " " << c << endl;
      int total = a + b + c;
      int _a = a, _b = b, _c = c, _t = total;
      while (total <= MAXN) {
	dic[total].insert(make_pair(a, make_pair(b, c)));
	a += _a, b += _b, c += _c, total += _t;
      }
    }
  }
  int res = 0;
  FOR(i,1,MAXN) {
    if (dic[i].size() == 1) ++res;
  }
  cout << "**" << endl;
  cout << dic[120].size() << endl;
  cout << "**" << endl;
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
