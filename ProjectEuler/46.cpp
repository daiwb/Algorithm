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
  if ( !t.empty() ) {
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

int plist[10000],pcount=0;
int mm[50000];

int prime(int n){
  int i;
  if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
    return 0;
  for (i=0;plist[i]*plist[i]<=n;i++)
    if (!(n%plist[i]))
      return 0;
  return n>1;
}

void initprime(){
  int i;
  mm[2] = 1;
  for (plist[pcount++]=2,i=3;i<50000;i++)
    if (prime(i)) {
      mm[i] = 1;
      plist[pcount++]=i;
    }
}

void run() {
  initprime();
  for (int i = 35; i < 50000; i += 2) {
    if (mm[i] == 1) continue;
    for (int j = 1; j < pcount; ++j) {
      if (plist[j] > i) {
	cout << i << endl;
	return;
      }
      int a = (i - plist[j]) / 2;
      int b = (int) sqrt(a + 0.5);
      if (b * b == a) break;
    }
  }
}

int main() {
  run();
}
