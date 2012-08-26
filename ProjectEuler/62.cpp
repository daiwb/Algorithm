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

string i2s(LL n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

map<string, vector<int> > dic;
map<string, vector<int> >::iterator itr;

void run() {
  FOR(i,5,10000) {
    LL t = i * i;
    t *= i;
    string str = i2s(t);
    sort(str.begin(), str.end());
    itr = dic.find(str);
    if (itr == dic.end()) {
      dic[str] = vector<int>();
      dic[str].push_back(i);
    } else {
      dic[str].push_back(i);
      if (dic[str].size() == 5) {
	//REP(k,5) cout << dic[str][k] << endl;
	LL res = dic[str][0];
	cout << res * res * res << endl;
	return;
      }
    }
  }
}

int main() {
  run();
}
