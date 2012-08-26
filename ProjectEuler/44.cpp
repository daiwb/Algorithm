/**
 * Problem: 
 * Algorithm: 
 * Author: daiwb
 * Date: 2008/
 */

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

vector<int>::iterator itr;

void run() {
  int res = -1;
  vector<int> mm;
  mm.push_back(1);
  mm.push_back(5);
  mm.push_back(12);
  mm.push_back(35);
  for (int i = 5; ; ++i) {
    int n = i * (i * 3 - 1) / 2;
    if (res != -1 && n > res * 3) break;
    cout << n << endl;
    mm.push_back(n);
    for (int j = mm.size() - 2; j >= 2; --j) {
      int t = mm[j];
      int a = n - t;
      if (a > t) continue;
      itr = find(mm.begin(), mm.end(), a);
      if (itr == mm.end()) continue;
      int b = t - a;
      itr = find(mm.begin(), mm.end(), b);
      if (itr == mm.end()) continue;
      if (res == -1) res = t - a;
      else res = min(res, t - a);
    }
  }
  cout << res << endl;
}

int main() {
  run();
}
