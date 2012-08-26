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

int mm[4];

bool isPrime(int n) {
  if (n == 1) return false;
  if (n == 2 || n == 3 || n == 5 || n == 7) return true;
  if ((n & 1) == 0) return false;
  int mid = (int) sqrt(n + 0.5);
  for (int i = 3; i <= mid; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void run() {
  for (mm[0] = 1; mm[0] <= 9; ++mm[0]) {
    for (mm[1] = 0; mm[1] <= 9; ++mm[1]) {
      for (mm[2] = 0; mm[2] <= 9; ++mm[2]) {
	for (mm[3] = 0; mm[3] <= 9; ++mm[3]) {
	  int a = mm[0] * 1000 + mm[1] * 100 + mm[2] * 10 + mm[3];
	  int b = a + 3330;
	  int c = b + 3330;
	  if (!isPrime(a)) continue;
	  if (!isPrime(b)) continue;
	  if (!isPrime(c)) continue;
	  string sa = i2s(a);
	  string sb = i2s(b);
	  string sc = i2s(c);
	  sort(sa.begin(), sa.end());
	  sort(sb.begin(), sb.end());
	  sort(sc.begin(), sc.end());
	  if (sa != sb || sa != sc) continue;
	  cout << a << " " << b << " " << c << " " << endl;
	}
      }
    }
  }
}

int main() {
  run();
}
