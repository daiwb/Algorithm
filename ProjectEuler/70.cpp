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

#define MAXN 10000000

int plist[1000000],pcount=0;

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
  for (plist[pcount++]=2,i=3;i<MAXN;i++)
    if (prime(i))
      plist[pcount++]=i;
}

int mm[MAXN + 5];

void run() {
  initprime();
  cout << pcount << " " << plist[pcount - 1] << endl;
  FOR(i,2,MAXN-1) mm[i] = i;
  REP(i,pcount) {
    int p = plist[i];
    for (int s = p; s < MAXN; s += p) {
      mm[s] = (LL) mm[s] * (p - 1) / p;
    }
  }
  double mi = 87109.0 / 79180.0;
  int idx = 87109;
  FOR(i,2,MAXN-1) {
    string s1 = i2s(i);
    string s2 = i2s(mm[i]);
    if (s1.length() != s2.length()) continue;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2) {
      double temp = i * 1.0 / mm[i];
      if (temp < mi) {
	mi = temp;
	idx = i;
      }
    }
  }
  cout << idx << " - " << mm[idx] << endl;
}

int main() {
  run();
}
