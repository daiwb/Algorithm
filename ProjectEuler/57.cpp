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

string add(string a, string b) {
  if (a.length() > b.length()) swap(a, b);
  int add = 0;
  REP(i,a.length()) {
    int t = a[i] - '0' + b[i] - '0' + add;
    b[i] = t % 10 + '0';
    add = t / 10;
  }
  FOR(i,a.length(),b.length()-1) {
    int t = b[i] - '0' + add;
    b[i] = t % 10 + '0';
    add = t / 10;
  }
  if (add == 1) b += "1";
  return b;
}

void run() {
  int res = 0;
  REP(i,1000) {
    string a = "1", b = "2";
    REP(j,i) {
      a = add(a, add(b, b));
      swap(a, b);
    }
    a = add(a, b);
    cout << "i = " << i + 1 << endl;
    cout << a << endl << "---" << endl << b << endl;
    if (a.length() > b.length()) ++res;
  }
  cout << res << endl;
}

int main() {
  run();
}
