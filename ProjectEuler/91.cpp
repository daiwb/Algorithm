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

int gcd(int a, int b) {
  while (true) {
    if (b == 0) break;
    a %= b;
    a ^= b ^= a ^= b;
  }
  return a;
}

#define MAXN 50

void run() {
  int res = 0;
  res += MAXN * MAXN * 3;
  int t = 0;
  FOR(i,1,MAXN) {
    FOR(j,1,MAXN) {
      int g = gcd(i, j);
      int dx = j / g, dy = i / g;
      int tx = i, ty = j;
      while (true) {
	tx += dx, ty -= dy;
	if (tx > MAXN || ty < 0) break;
	++t;
      }
      tx = i, ty = j;
      while (true) {
	tx -= dx, ty += dy;
	if (tx < 0 || ty > MAXN) break;
	++t;
      }
    }
  }
  res += t;
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
