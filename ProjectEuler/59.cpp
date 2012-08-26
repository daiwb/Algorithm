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

void run() {
  string input;
  cin >> input;
  vector<int> mm = splitInt(input, ",");
  string letter = " !\"'(),-.0123456789:;?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  int key[3];
  REP(m,3) {
    FOR(i,'a','z') {
      bool flag = true;
      for (int j = m; j < mm.size(); j += 3) {
	char t = char(i ^ mm[j]);
	string::size_type idx = letter.find(t);
	if (idx == string::npos) {
	  flag = false;
	  break;
	}
      } 
      if (flag) key[m] = i;
    }
  }

  int res = 0;
  int now = 0;
  REP(i,mm.size()) {
    res += (mm[i] ^ key[now]);
    now = (now + 1) % 3;
  }

  cout << res << endl;
}

int main() {
  run();
}
