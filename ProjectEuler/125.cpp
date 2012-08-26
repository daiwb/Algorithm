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

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

#define MAXN 100000000

int mm[MAXN + 1];

int sq[10001];

void init() {
    FOR(i,1,10000) sq[i] = i * i;
}

bool ispal(string s) {
    int len = s.length();
    REP(i,len/2) {
        if (s[i] != s[len - 1 - i]) return false;
    }
    return true;
}

void run() {
    init();
    memset(mm, 0, sizeof(mm));
    FOR(i,1,10000) {
        int t = sq[i];
        FOR(j,i+1,10000) {
            t += sq[j];
            if (t > MAXN) break;
            mm[t] = 1;
        }
    }

    LL res = 0;
    FOR(i,1,MAXN) {
        if (mm[i] == 0) continue;
        if (ispal(i2s(i))) res += i;
    }
    cout << res << endl;
}

int main() {
    run();
}
