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

vector<vector<int> > a;
int mm[80][80];

int dp(int r, int c) {
  int& ret = mm[r][c];
  if (ret != -1) return ret;
  if (r == 79 && c == 79) return ret = a[r][c];

  ret = 2000000000;
  if (r != 79) {
    int t = a[r][c] + dp(r + 1, c);
    ret = min(ret, t);
  }
  if(c != 79) {
    int t = a[r][c] + dp(r, c + 1);
    ret = min(ret, t);
  }

  return ret;
}

void run() {
  a.clear();
  REP(i,80) {
    string str;
    cin >> str;
    vector<int> t = splitInt(str, ",");
    a.push_back(t);
  }
  memset(mm, -1, sizeof(mm));
  cout << dp(0, 0) << endl;
}

int main() {
  run();
}
