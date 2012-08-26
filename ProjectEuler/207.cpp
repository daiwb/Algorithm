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

void run() {
  for (LL n = 1; n <= 1000000; ++n) {
    LL t = n * (n + 1);
    LL m = (LL) (log(n + 1.0) / log(2.0));
    //cout << t << " " << m << "/" << n << endl;
    if (m * 12345 < n) {
      cout << t << " " << m << "/" << n << endl;
      return;
    }
  }
}

int main () {
  run();
  return 0;
}
