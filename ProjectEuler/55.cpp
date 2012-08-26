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

string add(string a, string b) {
  if (a.length() < b.length()) swap(a, b);
  int la = a.length(), lb = b.length();
  int mm = 0;
  REP(i,lb) {
    a[i] += b[i] + mm;
    mm = a[i] / 10;
    a[i] %= 10;
  }
  FOR(i,lb,la-1) {
    a[i] += mm;
    mm = a[i] / 10;
    a[i] %= 10;
  }
  if (mm > 0) a = a + char(mm);
  return a;
}

bool isok(int n) {
  string s = i2s(n);
  REP(i,s.length()) s[i] -= '0';
  reverse(s.begin(), s.end());
  int steps = 0;
  while (true) {
    ++steps;
    if (steps == 50) return false;
    string t = s;
    reverse(t.begin(), t.end());
    s = add(s, t);
    int len = s.length();
    bool flag = true;
    REP(j,len/2) {
      if (s[j] != s[len - 1 - j]) {
	flag = false;
	break;
      }
    }
    if (flag) return true;
  }
  return false;
}

void run() {
  int res = 0;
  FOR(i,1,9999) {
    //cout << "i = " << i << " - ";
    if (isok(i)) {
      //cout << true << endl;
    } else {
      //cout << false << endl;
      ++res;
    }
  }
  cout << res << endl;
}

int main() {
  run();
}
