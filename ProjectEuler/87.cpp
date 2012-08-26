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
  if (!t.empty() ) {
    res.push_back(t);
  }
  return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
  vector<string> tok = split( s, delim );
  vector<int> res;
  for ( int i = 0 ; i != tok.size(); i++ )
    res.push_back( atoi( tok[i].c_str() ) );
  return res;
}

LL gcd(LL a,LL b){
  return b?gcd(b,a%b):a;
}

inline LL lcm(LL a,LL b){
  return a/gcd(a,b)*b;
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

#define MAXN 50000000

LL p2[10000], p3[10000], p4[10000];

void initprime(){
  int i;
  for (plist[pcount++]=2,i=3;i<50000;i++)
    if (prime(i))
      plist[pcount++]=i;

  REP(i,pcount) {
    int t = plist[i];
    t *= plist[i]; p2[i] = t;
    if (t > MAXN) break;
    t *= plist[i]; p3[i] = t;
    if (t > MAXN) continue;
    t *= plist[i]; p4[i] = t;
    if (t > MAXN) continue;
  }
}

int mm[MAXN + 5];

void run() {
  memset(mm, 0, sizeof(mm));
  REP(i,pcount) {
    LL t1 = p2[i];
    if (t1 > MAXN) break;
    REP(j,pcount) {
      LL t2 = t1 + p3[j];
      if (t2 > MAXN) break;
      REP(k,pcount) {
	LL t3 = t2 + p4[k];
	if (t3 > MAXN) break;
	mm[t3] = 1;
      }
    }
  }
  int ret = 0;
  FOR(i,1,MAXN-1) if (mm[i] > 0) ++ret;
  cout << ret << endl;
}

int main() {
  initprime();
  run();
}
