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

class state {
public:
  int n;
  int rad;
  state(int _n, int _rad) : n(_n), rad(_rad) {}
  bool operator<(const state& rhs) const {
    if (rad != rhs.rad) return rad < rhs.rad;
    return n < rhs.n;
  }
};

#define MAXN 100000
int mm[MAXN + 1];

void run() {
  memset(mm, 0, sizeof(mm));
  mm[1] = 1;
  FOR(i,2,MAXN) {
    if (mm[i] != 0) continue;
    for (int j = i; j <= MAXN; j += i) {
      if (mm[j] == 0) mm[j] = i;
      else mm[j] *= i;
    }
  }
  vector<state> dd;
  FOR(i,1,MAXN) {
    dd.push_back(state(i, mm[i]));
  }
  sort(dd.begin(), dd.end());
  cout << dd[9999].n << endl;
}

int main() {
  run();
}
