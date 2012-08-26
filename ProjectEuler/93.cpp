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

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

string i2s(LL n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

int idx, mx;
double t;
int mm[4];
string res;
vector<int> tmp;
vector<int> vv;

void go(int now) {
  if (now == 4) {
    if (t >= 1) {
      if (zero(t - (int)t)) vv.push_back((int)t);
    }
    return;
  }

  double bk = t;

  t = bk * tmp[now];
  go(now + 1);

  t = bk + tmp[now];
  go(now + 1);

  t = bk - tmp[now];
  go(now + 1);

  t = tmp[now] - bk;
  go(now + 1);

  if (bk != 0) {
    t = tmp[now] / bk;
    go(now + 1);
  }

  if (tmp[now] != 0) {
    t = bk / tmp[now];
    go(now + 1);
  }
}

vector<double> doit(double a, double b) {
  vector<double> ret;
  ret.push_back(a + b);
  ret.push_back(a * b);
  ret.push_back(a - b);
  ret.push_back(b - a);
  if (b != 0) ret.push_back(a / b);
  if (a != 0) ret.push_back(b / a);
  return ret;
}

void check() {
  tmp.clear();
  REP(i,4) tmp.push_back(mm[i]);
  vv.clear();
  do {
    t = tmp[0];
    go(1);
  } while (next_permutation(tmp.begin(), tmp.end()));
  
  vector<double> aa = doit(tmp[0], tmp[1]), bb = doit(tmp[2], tmp[3]);
  REP(i,aa.size()) {
    REP(j,bb.size()) {
      vector<double> tt = doit(aa[i], bb[j]);
      REP(k,tt.size()) {
        if (tt[k] >= 1) {
          if (zero(tt[k] - (int) tt[k])) vv.push_back((int)tt[k]);
        }
      }
    }
  }

  sort(vv.begin(), vv.end());
  vv.erase(unique(vv.begin(), vv.end()), vv.end());
  int n = 0, last = 0;
  REP(i,vv.size()) {
    if (vv[i] != last + 1) break;
    ++n, ++last;
  }
  if (n > mx) {
    mx = n;
    res = "";
    REP(j,4) res += i2s(tmp[j]);
  }
}

void dfs(int now) {
  if (now == 4) {
    check();
    return;
  }

  int s = (now == 0 ? -1 : mm[now - 1]);
  FOR(i,s+1,9) {
    mm[now] = i;
    dfs(now + 1);
  }
}

void run() {
  mx = -1;
  dfs(0);
  cout << res << " " << mx << endl;
}

int main () {
  run();
  return 0;
}
