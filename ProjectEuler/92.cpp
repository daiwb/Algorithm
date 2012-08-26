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

int mm[100000005];

int dp(int n) {
  int& ret = mm[n];
  if (ret != -1) return ret;

  string s = i2s(n);
  int t = 0;
  REP(i,s.length()) {
    t += (s[i] - '0') * (s[i] - '0');
  }
  ret = dp(t);
  return ret;
}

void run() {
  int res = 0;
  memset(mm, -1, sizeof(mm));
  mm[1] = 0;
  mm[89] = 1;
  FOR(i,1,9999999) {
    int t = dp(i);
    //cout << "i = " << i << ", t = " << t << endl;
    if (t == 1) ++res;
  }
  cout << res << endl;
}

int main() {
  run();
}
