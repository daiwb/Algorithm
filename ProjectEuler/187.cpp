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

#define MAXN 100000000

int mm[MAXN + 1];
vector<int> dd;

void run() {
  memset(mm, 0, sizeof(mm));
  for (int i = 4; i < MAXN; i += 2) mm[i] = 1;
  LL res = 1;
  dd.push_back(2);
  int end = MAXN >> 1;
  for (int i = 3; i < end; i += 2) {
    //if ((i - 1) % 1000000 == 0) cout << i << endl;
    if (mm[i] == 1) continue;
    dd.push_back(i);
    int l = 0, r = dd.size() - 1, cnt;
    while (true) {
      if (l == r) {
	cnt = l;
	break;
      }
      if (l + 1 == r) {
	if ((LL) dd[r] * i < MAXN) cnt = r;
	else cnt = l;
	break;
      }
      int mid = (l + r) >> 1;
      if ((LL) dd[mid] * i < MAXN) l = mid;
      else r = mid - 1;
    }
    res += cnt + 1;
    int t = i;
    while (true) {
      t += i;
      if (t >= MAXN) break;
      mm[t] = 1;
    }
  }
  cout << dd.size() << endl;
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
