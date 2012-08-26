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
#define MAXN 400001
#define MAXK 41

LL rrss[MAXN], ffss[MAXN];
LL mm[MAXK][2][2];

void init(int n, LL a[MAXN], int first, int prod, int add, int mod) {
    a[0] = first % mod;
    FOR(i,1,n-1) {
        a[i] = (a[i - 1] * prod + add) % mod;
    }
}

class RoadOrFlightHard {
public:
    long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
        init(N, rrss, roadFirst, roadProd, roadAdd, roadMod);
        init(N, ffss, flightFirst, flightProd, flightAdd, flightMod);
        
        FOR(i,0,K) mm[i][0][0] = mm[i][0][1] = 0;
        int now = 0, prev = 1;
        RFOR(i,N-1,0) {
            swap(now, prev);

            FOR(j,0,K) {
                mm[j][now][0] = mm[j][prev][0] + rrss[i];
                if (j > 0) mm[j][now][0] = min(mm[j][now][0], mm[j - 1][prev][1] + ffss[i]);

                mm[j][now][1] = mm[j][prev][1] + ffss[i];
                mm[j][now][1] = min(mm[j][now][1], mm[j][prev][0] + rrss[i]);
            }
        }

        LL res = mm[K][now][0];
        if (K > 0) res = min(res, mm[K - 1][now][1]);

        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        RoadOrFlightHard theObject;
        eq(0, theObject.minTime(3, 14, 1, 2, 10, 18, 1, 10, 17, 1),14LL);
    }
    {
        RoadOrFlightHard theObject;
        eq(1, theObject.minTime(3, 4, 1, 2, 10, 1, 1, 10, 17, 2),11LL);
    }
    {
        RoadOrFlightHard theObject;
        eq(2, theObject.minTime(3, 4, 1, 2, 10, 1, 1, 6, 9, 1),12LL);
    }
    {
        RoadOrFlightHard theObject;
        eq(3, theObject.minTime(5, 85739, 94847, 93893, 98392, 92840, 93802, 93830, 92790, 3),122365LL);
    }
    
    return 0;
}
// END CUT HERE
