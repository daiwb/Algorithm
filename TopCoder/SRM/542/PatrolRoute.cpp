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

#define MOD 1000000007

class PatrolRoute {
public:
    int countRoutes(int X, int Y, int minT, int maxT) {
        LL xx[4005] = {0}, yy[4005] = {0};
        REP(i,X) FOR(j,i+2,X-1) xx[j - i] += j - i - 1;
        REP(i,Y) FOR(j,i+2,Y-1) yy[j - i] += j - i - 1;
        LL res = 0;
        REP(i,X) REP(j,Y)
            if ((i + j) * 2 >= minT && (i + j) * 2 <= maxT) {
                res = (res + xx[i] * yy[j]) % MOD;
            }
        return res * 6 % MOD;
    }
};
// BEGIN CUT HERE
int main() {
    {
        PatrolRoute theObject;
        eq(0, theObject.countRoutes(3, 3, 1, 20000),6);
    }
    {
        PatrolRoute theObject;
        eq(1, theObject.countRoutes(3, 3, 4, 7),0);
    }
    {
        PatrolRoute theObject;
        eq(2, theObject.countRoutes(4, 6, 9, 12),264);
    }
    {
        PatrolRoute theObject;
        eq(3, theObject.countRoutes(7, 5, 13, 18),1212);
    }
    {
        PatrolRoute theObject;
        eq(4, theObject.countRoutes(4000, 4000, 4000, 14000),859690013);
    }
    {
        PatrolRoute theObject;
        eq(4, theObject.countRoutes(4000, 4000, 1, 20000),841484969);
    }
    {
        PatrolRoute theObject;
        eq(4, theObject.countRoutes(2500, 4000, 1, 19000),946772779);
    }
    return 0;
}
// END CUT HERE
