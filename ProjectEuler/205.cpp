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

int peter[40];
int colin[40];
int tmp[40];
int sc[40];

void run() {
    memset(peter, 0, sizeof(peter));
    memset(colin, 0, sizeof(colin));
    memset(sc, 0, sizeof(sc));

    FOR(i,1,4) peter[i] = 1;
    FOR(i,2,9) {
        memset(tmp, 0, sizeof(tmp));
        FOR(j,1,4) {
            FOR(k,1,(i-1)*4) {
                if (peter[k] > 0) {
                    tmp[k + j] += peter[k];
                }
            }
        }
        memcpy(peter, tmp, sizeof(tmp));
    }
    int tp = 1;
    REP(i,9) tp *= 4;

    FOR(i,1,6) colin[i] = 1;
    FOR(i,2,6) {
        memset(tmp, 0, sizeof(tmp));
        FOR(j,1,6) {
            FOR(k,1,(i-1)*6) {
                if (colin[k] > 0) tmp[k + j] += colin[k];
            }
        }
        memcpy(colin, tmp, sizeof(tmp));
    }
    FOR(i,1,36) sc[i] = sc[i - 1] + colin[i];
    int tc = 1;
    REP(i,6) tc *= 6;

    double ret = 0;
    FOR(i,1,36) {
        ret += 1.0 * peter[i] * sc[i - 1];
    }
    ret /= (1.0 * tp * tc);

    cout << ret << endl;
}

int main() {
    run();
}
