#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
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

void run() {
  double ret = 0;
  int idx = 0, now = 0;
  string str;
  while (cin >> str) {
    ++now;
    vector<int> mm = splitInt(str, ",");
    double base = mm[0];
    double exp = mm[1];
    double val = exp * log(base);
    if (val > ret) {
      ret = val;
      idx = now;
    }
  }
  cout << idx << endl;
}

int main() {
  run();
}
