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

int plist[80000],pcount=0;
int mm[1000005];

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
  for (plist[pcount++]=2,i=3;i<1000000;i++)
    if (prime(i)) {
      mm[i] = 1;
      plist[pcount++]=i;
    }
}

void run() {
  initprime();
  int t = 21;
  int res = 953;
  for (int i = 0; i < pcount; ++i) {
    int cnt = 0;
    LL sum = 0;
    for (int j = i; j < pcount; ++j) {
      ++cnt;
      sum += plist[j];
      if (sum >= 1000000) break;
      if (mm[sum] == 1 && cnt > t) {
	t = cnt;
	res = sum;
      }
    }
  }
  cout << t << " " << res << endl;
}

int main() {
  run();
}
