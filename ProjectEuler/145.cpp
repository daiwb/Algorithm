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
typedef long long LL;

#define MAXN 9

LL mm[10][2][2];

LL dp(int len, int a, int b) {
  LL& ret = mm[len][a][b];
  if (ret != -1) return ret;

  if (len == 1) {
    if (a == 0) return ret = 0;
    ret = 0;
    FOR(i,0,9) {
      int t = (i + i + a);
      if (t / 10 != b) continue;
      ++ret;
    }
    return ret;
  }

  if (len == 0) {
    if (a == b) return ret = 1;
    else return ret = 0;
  }

  ret = 0;
  FOR(i,0,9) {
    FOR(j,0,9) {
      int l = (i + j + a);
      if ((l & 1) == 0) continue;
      int r = (i + j);
      if (r / 10 != b) continue;
      ret += dp(len - 2, l / 10, 1 - r & 1);
    }
  }

  return ret;
}

void run() {
  memset(mm, -1, sizeof(mm));
  LL res = 0;
  FOR(len,2,MAXN) {
    FOR(i,1,9) {
      FOR(j,1,9) {
        if (((i + j) & 1) == 0) continue;
        res += dp(len - 2, (i + j) / 10, 1 - (i + j) & 1);
      }
    }
  }

  cout << res << endl;
}

int main () {
  run();
  return 0;
}
