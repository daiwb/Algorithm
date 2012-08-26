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

int mm[10][10];
int dd[10];
int vv[10];
int cnt;

void run() {
  memset(mm, 0, sizeof(mm));
  memset(vv, 0, sizeof(vv));
  string str;
  while (cin >> str) {
    int a = str[0] - '0';
    int b = str[1] - '0';
    int c = str[2] - '0';
    mm[a][b] = mm[a][c] = mm[b][c] = 1;
    vv[a] = vv[b] = vv[c] = 1;
  }
  REP(k,10) {
    REP(i,10) {
      REP(j,10) {
	if (mm[i][k] == 1 && mm[k][j] == 1) mm[i][j] = 1;
      }
    }
  }
  cnt = 0;
  REP(i,10) if (vv[i] == 1) ++cnt;
  memset(dd, 0, sizeof(dd));
  REP(i,10) {
    REP(j,10) {
      if (mm[i][j] == 1) ++dd[i];
    }
  }
  RFOR(i,cnt-1,0) {
    REP(j,10) {
      if (vv[j] == 0) continue;
      if (dd[j] == i) {
	cout << j;
	break;
      }
    }
  }
  cout << endl;
}

int main() {
  run();
}
