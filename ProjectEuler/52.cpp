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

string mm[6];

void run() {
  int n = 10;
  while (n++) {
    REP(i,6) mm[i] = i2s(n * (i + 1));
    if (mm[5].length() > mm[0].length()) continue;
    REP(i,6) sort(mm[i].begin(), mm[i].end());
    bool flag = true;
    FOR(i,1,5) {
      if (mm[i] != mm[0]) {
	flag = false;
	break;
      }
    }
    if (flag) {
      cout << n << endl;
      return;
    }
  }
}

int main() {
  run();
}
