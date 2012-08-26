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

#define BILLION 1000000000

void run() {
  LL res = 0;
  LL a = 3, len = 10;
  for (LL i = 2; ; ++i) {
    if (i % 100000000 == 0) cout << "*** " << i << " ***" << endl;

    LL len = (a + i) << 1;
    LL h2 = a * a - i * i;
    LL h = (LL) sqrt(h2 + 0.0);
    if (h * h == h2) {
      res += len;
      cout << i << " " << a << " " << len << endl;
    }
    
    len += 4;
    if (len > BILLION) break;
    a += 2;
    
    len = (a + i) << 1;
    h2 = a * a - i * i;
    h = (LL) sqrt(h2 + 0.0);
    if (h * h == h2) {
      res += len;
      cout << i << " " << a << " " << len << endl;
    }
    
    len += 2;
    if (len > BILLION) {
      break;
    }
  }
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
