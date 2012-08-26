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
typedef long long LL;

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

#define MOD 1000000007

class BricksN {
public:
    int countStructures(int maxw, int maxh, int k) {
        // Number of ways to construct consecutive bricks.
        vector<LL> mm(maxw + 1);
        mm[0] = 1;
        FOR(w,1,maxw) {
            FOR(b,1,min(w, k)) mm[w] = (mm[w] + mm[w - b]) % MOD;
        }

        LL res[2][55];
        FOR(w,1,maxw) res[0][w] = 1;
        FOR(h,1,maxh) {
            res[1][0] = 1;
            FOR(w,1,maxw) {
                // When the whole new column is empty.
                res[1][w] = res[1][w - 1];
                FOR(b,1,w) {
                    // Rightmost b bricks are filled (mm[b] ways), then an empty brick (all bricks above should be empty too).
                    res[1][w] = (res[1][w] + res[1][max(0, w - b - 1)] * mm[b] % MOD * res[0][b] % MOD) % MOD;
                }
            }
            memcpy(res[0], res[1], sizeof(res[1]));
        }
        return res[0][maxw];
    }
};
// BEGIN CUT HERE
int main() {
    {
        BricksN theObject;
        eq(0, theObject.countStructures(3, 2, 3),83);
    }
    {
        BricksN theObject;
        eq(0, theObject.countStructures(3, 1, 3),13);
    }
    {
        BricksN theObject;
        eq(1, theObject.countStructures(3, 2, 3),83);
    }
    {
        BricksN theObject;
        eq(2, theObject.countStructures(1, 5, 1),6);
    }
    {
        BricksN theObject;
        eq(3, theObject.countStructures(10, 10, 3),288535435);
    }
    return 0;
}
// END CUT HERE
