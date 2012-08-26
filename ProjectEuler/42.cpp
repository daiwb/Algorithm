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

int vv[200];

void init() {
  memset(vv, 0, sizeof(vv));
  int i = 1;
  while (true) {
    int n = i * (i + 1) / 2;
    if (n > 200) break;
    vv[n] = 1;
    ++i;
  }
}

void run() {
  init();
  int res = 0;
  string str;
  cin >> str;
  vector<string> dd = split(str, "\",");
  REP(k,dd.size()) {
    int t = 0;
    REP(i,dd[k].length()) {
      t += dd[k][i] - 'A' + 1;
    }
    if (vv[t]) ++res;
  }
  cout << res << endl;
}

int main() {
  run();
}
