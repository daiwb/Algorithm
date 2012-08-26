#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
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

string i2s(LL n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

vector<int> mm;

void run() {
    FOR(i,1010,1389) {
        REP(j,mm.size()) {
            LL t = i * 100000 + mm[j];
            LL q = t;
            t *= t;
            string s = i2s(t);
            bool flag = true;
            for (int i = 0; i < s.length(); i += 2) {
                if (s[i] != '1' + (i >> 1)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << q << "0" << endl;
                cout << s << "00" << endl;
                return;
            }
        }
    }
}

int main() {
    FOR(i,1,99999) {
        LL t = i + 100000;
        t *= t;
        string s = i2s(t);
        int len = s.length();
        if (s[len - 1] == '9' && s[len - 3] == '8' && s[len - 5] == '7') {
            mm.push_back(i);
        }
    }
    run();
}
