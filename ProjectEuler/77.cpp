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

int plist[10000],pcount=0;

int prime(int n){
  int i;
  if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
    return 0;
  for (i=0;plist[i]*plist[i]<=n;i++)
    if (!(n%plist[i]))
      return 0;
  return n>1;
}

void initprime(){
  int i;
  for (plist[pcount++]=2,i=3;i<50000;i++)
    if (prime(i))
      plist[pcount++]=i;
}

#define MAXN 5000
int mm[MAXN + 1][5200];

int dp(int n, int idx) {
  int& ret = mm[n][idx];
  if (ret != -1) return ret;

  if (n == 0) return ret = 1;
  if (idx >= pcount) return ret = 0;
  if (plist[idx] > n) return ret = 0;

  ret = dp(n, idx + 1);
  int t = n;
  while (true) {
    t -= plist[idx];
    if (t < 0) break;
    ret += dp(t, idx + 1);
  }

  return ret;
}

void run() {
  initprime();
  cout << pcount << " " << plist[pcount - 1] << endl;
  memset(mm, -1, sizeof(mm));
  //cout << dp(10, 0) << endl;
  FOR(i,1,MAXN) {
    int t = dp(i, 0);
    if (t > 5000) {
      cout << i << " " << t << endl;
      break;
    }
  }
}

int main () {
  run();
  return 0;
}
