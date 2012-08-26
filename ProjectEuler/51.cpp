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

int plist[100000],pcount=0;
set<int> mm;

int prime(int n){
    int i;
    if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
        return 0;
    for (i=0;plist[i]*plist[i]<=n;i++)
        if (!(n%plist[i]))
            return 0;
    return n>1;
}

string str = "000000";

void initprime(){
    int i;
    for (plist[pcount++]=2,i=3;i<1000000;i+=2)
        if (prime(i)) {
            plist[pcount++]=i;
            if (i >= 100000) mm.insert(i);
        }
}

void doit() {
    if (str[0] == '0') return;
    if (str.find('*') == string::npos) return;
    if (str[5] == '0' || str[5] == '2' || str[5] == '4' || str[5] == '5' || str[5] == '6' || str[5] == '8') return;
    vector<int> dd;
    REP(i,10) {
        if (i == 0 && str[0] == '*') continue;
        string s = str;
        REP(j,s.length()) {
            if (s[j] == '*') s[j] = i + '0';
        }
        int val = s2i(s);
        if (mm.find(val) != mm.end()) dd.push_back(val);
    }
    if (dd.size() == 8) {
        REP(i,dd.size()) cout << dd[i] << " ";
        cout << endl;
        return;
    }
}

void dfs(int idx) {
    if (idx == 6) {
        //doit();
        return;
    }
    str[idx] = '*';
    dfs(idx + 1);

    REP(i,10) {
        str[idx] = i + '0';
        dfs(idx + 1);
    }
}

void run() {
    initprime();
    dfs(0);
}

int main() {
    run();
}
