// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

// BEGIN CUT HERE
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

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// END CUT HERE

// BEGIN CUT HERE
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
// END CUT HERE

#define INF 1000000000

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

inline int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

int mm[55][2505];
string str;
int n, len, K, C;

bool isok(int pos, int t) {
    if (str[pos] == 'K' && ((t % K) != 0)) {
        return true;
    }
    if (str[pos] == 'C' && ((t % C) == 0)) {
        return true;
    }
    if (str[pos] == '.') {
        return true;
    }
    return false;
}

int dp(int now, int t) {
    int& ret = mm[now][t];
    if (ret != -1) return ret;

    if (now == len - 1) return ret = 0;

    ret = INF;

    if (str[now + 1] == '.') {
        return ret = min(ret, dp(now + 1, (t + 1) % n) + 1);
    }

    FOR(i,1,n) {
        int nt = t + i;
        if (isok(now + 1, nt % n)) {
            int tmp = dp(now + 1, nt % n);
            if (tmp != INF) ret = min(ret, tmp + i);
        }
        if (str[now] == 'K' && ((nt % K) == 0)) {
            break;
        }
        if (str[now] == 'C' && ((nt % C) != 0)) {
            break;
        }
    }

    return ret;
}

class KindAndCruel {
public:
    int crossTheField(string field, int _K, int _C) {
        str = field;
        len = str.length();
        K = C = 1;
        REP(i,len) {
            if (str[i] == 'K') K = _K;
            if (str[i] == 'C') C = _C;
        }
        n = lcm(K, C);
        memset(mm, -1, sizeof(mm));
        int res = dp(0, 0);
        return res == INF ? -1 : res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        KindAndCruel theObject;
        eq(0, theObject.crossTheField("..................................................", 49, 50),49);
    }
    {
        KindAndCruel theObject;
        eq(0, theObject.crossTheField("...", 2, 5),2);
    }
    {
        KindAndCruel theObject;
        eq(1, theObject.crossTheField(".K.C.", 3, 4),5);
    }
    {
        KindAndCruel theObject;
        eq(2, theObject.crossTheField(".CCCC.", 3, 5),-1);
    }
    {
        KindAndCruel theObject;
        eq(3, theObject.crossTheField(".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK.", 5, 5),60);
    }
    {
        KindAndCruel theObject;
        eq(0, theObject.crossTheField(".C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.", 49, 48),1105);
    }
    return 0;
}
// END CUT HERE
