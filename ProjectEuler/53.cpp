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

int mm[105][105];

#define MX 1000000

void run() {
  int res = 0;
  FOR(i,1,100) mm[i][0] = mm[i][i] = 1;
  FOR(i,1,100) {
    FOR(j,1,i-1) {
      mm[i][j] = mm[i - 1][j] + mm[i - 1][j - 1];
      //cout << "C(" << i << "," << j << ")=" << mm[i][j] << endl;
      if (mm[i][j] > MX) {
	++res;
	mm[i][j] = MX;
      }
    }
  }
  cout << res << endl;
}

int main() {
  run();
}
