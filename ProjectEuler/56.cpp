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

string mul(string a, string b) {
  string res = "0"; res[0] = char(0);
  REP(i,b.length()) {
    string t = a;
    int mm = 0;
    REP(j,t.length()) {
      t[j] = t[j] * b[i] + mm;
      mm = t[j] / 10;
      t[j] %= 10;
    }
    if (mm > 0) t = t + char(mm);
    res = add(res, t);
    a = char(0) + a;
  }
  return res;
}

void run() {
  int res = 0;
  FOR(i,1,100) {
    string si = i2s(i);
    reverse(si.begin(), si.end());
    REP(q,si.length()) si[q] -= '0';
    string t = "1"; t[0] = 1;
    t[0] = 1;
    FOR(j,1,100) {
      t = mul(t, si);
      //cout << i << " - " << j << " ";
      RFOR(k,t.length()-1,0) cout << char(t[k] + '0');
      cout << endl;
      int sum = 0;
      REP(k,t.length()) sum += t[k];
      res = max(res, sum);
    }
  }
  cout << res << endl;
}

int main() {
  run();
}
