#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
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

#define MAXN 10000


int plist[80000],pcount=0;

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
  for (plist[pcount++]=2,i=3;i<1000000;i++)
    if (prime(i))
      plist[pcount++]=i;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

void run() {
  LL ret = 0;
  FOR(i,3,MAXN) {
    int l, r;
    l = i / 3 + 1;
    if ((i & 1) == 0) r = (i >> 1) - 1;
    else r = (i >> 1);
    if ((i & 1) == 0) {
      if ((l & 1) == 0) ++l;
      if ((r & 1) == 0) --r;
    }
    //cout << i << " " << l << " " << r << endl;
    int d = 1;
    if ((i & 1) == 0) ++d;
    for (int j = l; j <= r; j += d) {
      if (gcd(i, j) == 1) ++ret;
    }
    //if (i % 1000 == 0) cout << i << endl;
  }
  cout << ret << endl;
}

int main() {
  run();
}
