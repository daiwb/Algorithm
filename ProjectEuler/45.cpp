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

void run() {
  for (LL i = 286; ; ++i) {
    LL t = i * (i + 1) / 2;

    //cout << t << endl;

    LL a = t * 24 + 1;
    LL b = (LL) sqrt(a + 0.5);
    //cout << a << " " << b << endl;
    if (b * b != a) continue;
    if ((b + 1) % 6 != 0) continue;

    a = t * 8 + 1;
    b = (LL) sqrt(a + 0.5);
    if (b * b != a) continue;
    if ((b + 1) % 4 != 0) continue;

    cout << t << endl;
    return;
  }
}

int main() {
  run();
}
