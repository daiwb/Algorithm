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
int mm[55][2][2][2];
int state[55];
int n;

class EllysLamps {
public:
    int dp(int idx, int lit, int addU, int addN) {
        int& ret = mm[idx][lit][addU][addN];
        if (ret != -1) return ret;

        if (idx == n - 1) return min(lit + addN, !lit + addU);

        ret = 0;
        REP(lt,2) {
            REP(rt,2) {
                int t1 = dp(idx + 1, state[idx + 1] ^ rt, lit ^ lt ^ 1, lit ^ 1) + addU;
                int t2 = dp(idx + 1, state[idx + 1], lit ^ lt, lit) + addN;
                ret = max(ret, min(t1, t2));
            }
        }

        return ret;
    }
    int getMin(string lamps) {
        n = lamps.length();
        REP(i,n) state[i] = lamps[i] == 'Y';
        memset(mm, -1, sizeof(mm));
        int res = dp(0, state[0], 0, 0);
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        EllysLamps theObject;
        eq(0, theObject.getMin("YNNYN"),2);
    }
    {
        EllysLamps theObject;
        eq(1, theObject.getMin("NNN"),0);
    }
    {
        EllysLamps theObject;
        eq(2, theObject.getMin("YY"),0);
    }
    {
        EllysLamps theObject;
        eq(3, theObject.getMin("YNYYYNNNY"),3);
    }
    {
        EllysLamps theObject;
        eq(4, theObject.getMin("YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"),13);
    }
    return 0;
}
// END CUT HERE
