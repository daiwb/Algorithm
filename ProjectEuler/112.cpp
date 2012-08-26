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

bool isBouncy(int n) {
  string s = i2s(n);
  bool up = false, down = false;
  FOR(i,1,s.length()-1) {
    if (s[i] > s[i - 1]) up = true;
    else if (s[i] < s[i - 1]) down = true;
    if (up & down) return true;
  }
  return false;
}

void run() {
  int dest = 2178 * 99;
  int cur = 2178 * 9;
  int now = 21780;
  while (true) {
    ++now;
    //if (now == 5000000) break;
    if (isBouncy(now)) ++cur;
    else dest += 99;
    if (cur == dest) {
      cout << dest << endl;
      cout << dest / 99 * 100 << endl;
      return;
    }
  }
}

int main() {
  run();
}
