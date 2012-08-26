/**
 * Problem: 
 * Algorithm: 
 * Author: daiwb
 * Date: 2008/
 */

#include <iostream>
#include <sstream>
#include <algorithm>
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

int dd[] = {1, 2, 3, 5, 7, 11, 13, 17};

void run() {
  LL res = 0;
  vector<int> mm;
  REP(i,10) mm.push_back(i);
  do {
    if (mm[0] == 0) continue;
    bool flag = true;
    FOR(i,1,7) {
      int t = mm[i] * 100 + mm[i + 1] * 10 + mm[i + 2];
      if (t % dd[i] != 0) {
	flag = false;
	break;
      }
    }
    if (flag) {
      LL t = 0;
      REP(i,10) t = t * 10 + mm[i];
      res += t;
    }
  } while (next_permutation(mm.begin(), mm.end()));
  cout << res << endl;
}

int main() {
  run();
}
