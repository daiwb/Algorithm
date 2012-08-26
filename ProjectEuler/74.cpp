#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

vector<string> split( const string& s, const string& delim =" " ) {
  vector<string> res;
  string t;
  for ( int i = 0 ; i != s.size() ; i++ ) {
    if ( delim.find( s[i] ) != string::npos ) {
      if ( !t.empty() ) {
	res.push_back( t );
	t = "";
      }
    } else {
      t += s[i];
    }
  }
  if ( !t.empty() ) {
    res.push_back(t);
  }
  return res;
}

int s2i(string s) {
  stringstream ss;
  ss << s;
  int res;
  ss >> res;
  return res;
}

string i2s(int n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

#define MAXN 1000000
#define INF 1000000000

int fact[10];
int next[MAXN * 3];

int getNext(int n) {
  int res = 0;
  while (n > 0) {
    res += fact[n % 10];
    n /= 10;
  }
  return res;
}

int mx = 0;

void init() {
  fact[0] = 1;
  FOR(i,1,9) fact[i] = fact[i - 1] * i;
  REP(i,MAXN*3) {
    next[i] = getNext(i);
    mx = max(mx, next[i]);
  }
  cout << mx << endl;
}

int mm[MAXN * 3];
vector<int> tp;

void doit(int now, int idx) {
  if (mm[now] < 0) {
    REP(i,tp.size()) mm[tp[i]] = -INF;
    return;
  }
  if (mm[now] > 0) {
    int len = idx - mm[now];
    int t = mm[now];
    FOR(i,t-1,idx-2) mm[tp[i]] = -len;
    FOR(i,0,t-2) mm[tp[i]] = -INF;
    return;
  }
  mm[now] = idx;
  tp.push_back(now);
  doit(next[now], idx + 1);
}

int dp(int n) {
  int& ret = mm[n];
  if (ret != 0) return ret;
  ret = dp(next[n]) + 1;
  return ret;
}

void run() {
  init();
  memset(mm, 0, sizeof(mm));
  FOR(i,1,MAXN-1) {
    if (i % 100000 == 0) cout << i << endl;
    if (mm[i] != 0) continue;
    tp.clear();
    doit(i, 1);
  }
  FOR(i,1,MAXN-1) {
    if (mm[i] == -INF) mm[i] = 0;
    if (mm[i] < 0) mm[i] = -mm[i];
  }
  int res = 0;
  FOR(i,1,MAXN-1) {
    int t = dp(i);
    if (t == 60) ++res;
  }
  cout << res << endl;
}

int main () {
  run();
  return 0;
}
