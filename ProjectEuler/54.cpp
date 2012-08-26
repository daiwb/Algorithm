#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
#include <map>
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

map<char, int> mp;

void init() {
  mp['2'] = 2;
  mp['3'] = 3;
  mp['4'] = 4;
  mp['5'] = 5;
  mp['6'] = 6;
  mp['7'] = 7;
  mp['8'] = 8;
  mp['9'] = 9;
  mp['T'] = 10;
  mp['J'] = 11;
  mp['Q'] = 12;
  mp['K'] = 13;
  mp['A'] = 14;
}

class state {
public:
  string val;
  state() {};
  bool operator<(const state& rhs) const {
    int a = mp[val[0]], b = mp[rhs.val[0]];
    if (a != b) return a < b;
    return val[1] < rhs.val[1];
  }
};

vector<string> p1(5);
vector<string> p2(5);
vector<state> tmp(5);

int getVal(vector<string> mm) {
  bool flag = true;

  REP(i,5) {
    if (mp[mm[i][0]] != 10 + i) {
      flag = false;
      break;
    }
  }
  if (flag) {
    FOR(i,1,4) {
      if (mm[i][1] != mm[0][1]) {
	flag = false;
	break;
      }
    }
  }
  if (flag) return 100000;

  flag = true;
  FOR(i,1,4) {
    if (mp[mm[i][0]] != mp[mm[i - 1][0]] + 1) {
      flag = false;
      break;
    }
  }
  if (flag) {
    FOR(i,1,4) {
      if (mm[i][1] != mm[0][1]) {
	flag = false;
	break;
      }
    }
  }
  if (flag) return 90000 + mp[mm[0][0]];

  if (mm[0][0] == mm[3][0] || mm[1][0] == mm[4][0]) return 80000 + mp[mm[1][0]];

  if (mm[0][0] == mm[1][0] && mm[3][0] == mm[4][0] && (mm[2][0] == mm[1][0] || mm[2][0] == mm[3][0])) {
    if (mm[2][0] == mm[1][0]) return 70000 + mp[mm[1][0]] * 100 + mp[mm[3][0]];
    else return 70000 + mp[mm[3][0]] * 100 + mp[mm[1][0]];
  }

  flag = true;
  FOR(i,1,4) {
    if (mm[i][1] != mm[0][1]) {
      flag = false;
      break;
    }
  }
  if (flag) return 60000;

  flag = true;
  FOR(i,1,4) {
    if (mp[mm[i][0]] != mp[mm[i - 1][0]] + 1) {
      flag = false;
      break;
    }
  }
  if (flag) return 50000 + mp[mm[0][0]];

  if (mm[0][0] == mm[2][0]) return 40000 + mp[mm[0][0]];
  if (mm[1][0] == mm[3][0]) return 40000 + mp[mm[1][0]];
  if (mm[2][0] == mm[4][0]) return 40000 + mp[mm[2][0]];

  if (mm[0][0] == mm[1][0] && (mm[2][0] == mm[3][0] || mm[3][0] == mm[4][0])) return 30000 + mp[mm[3][0]] * 100 + mp[mm[0][0]];
  if (mm[1][0] == mm[2][0] && mm[3][0] == mm[4][0]) return 30000 + mp[mm[3][0]] * 100 + mp[mm[1][0]];

  FOR(i,1,4) {
    if (mm[i][0] == mm[i - 1][0]) return 20000 + mp[mm[i][0]];
  }

  return 10000;
}

bool cmp(vector<string> p1, vector<string> p2) {
  //REP(i,5) cout << p1[i] << " ";
  //int v1 = getVal(p1), v2 = getVal(p2);
  //cout << v1 << " - " << v2 << " ";
  //REP(i,5) cout << p2[i] << " ";
  //cout << endl;
  if (v1 != v2) return v1 < v2;

  RFOR(i,4,0) {
    v1 = mp[p1[i][0]], v2 = mp[p2[i][0]];
    if (v1 != v2) return v1 < v2;
  }

  return true;
}

void run() {
  init();
  int win = 0;
  REP(i,1000) {
    REP(j,5) cin >> tmp[j].val;
    sort(tmp.begin(), tmp.end());
    REP(j,5) p1[j] = tmp[j].val;

    REP(j,5) cin >> tmp[j].val;
    sort(tmp.begin(), tmp.end());
    REP(j,5) p2[j] = tmp[j].val;

    if (!cmp(p1, p2)) {
      ++win;
      cout << "win" << endl;
    } else {
      cout << "lose" << endl;
    }
  }
  cout << win << endl;
}

int main() {
  run();
}
