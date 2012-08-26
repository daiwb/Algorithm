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
template<class T> inline int size(const T&c) {
    return c.size();
}
template<class A,class B> inline bool contains(const A&a,const B&b) {
    return find(a.begin(),a.end(),b)!=a.end();
}
int s2i(string s) {
    istringstream is(s); int x; is>>x; return x;
}
string i2s(int i) {
    stringstream ss; ss<<i; string x; ss>>x; return x;
}

#define see(n) cout << #n << " = " << n << endl
#define seeArray(n, a) cout << #a << " = ";\
for (int __i__ = 0; __i__ < n; ++__i__)\
    cout << a[__i__] << " ";\
    cout << endl;
#define seeArray2(n, m, a) cout << #a << " = " << endl;\
for (int __i__ = 0; __i__ < n; ++__i__) {\
    for (int __j__ = 0; __j__ < m; ++__j__)\
        cout << a[__i__][__j__] << " ";\
            cout << endl;\
}

const int INF = 2147483647;
// END CUT HERE

class StreetWalking {
    public:
        long long minTime(int X, int Y, int walkTime, int sneakTime) {
            if (X > Y) swap(X, Y);

            LL res = 0;

            if (walkTime * 2 <= sneakTime) res += (LL)X * 2 * walkTime;
            else res += (LL)X * sneakTime;

            LL n = Y - X;

            if (walkTime < sneakTime) res += (n / 2) * 2 * walkTime;
            else res += (n / 2) * 2 * sneakTime;

            res += (n % 2) * walkTime;

            return res;
        }
        
};
// BEGIN CUT HERE
int main() {
    {
        StreetWalking theObject;
        eq(0, theObject.minTime(4, 2, 3, 10),18LL);
    }
    {
        StreetWalking theObject;
        eq(1, theObject.minTime(4, 2, 3, 5),16LL);
    }
    {
        StreetWalking theObject;
        eq(2, theObject.minTime(2, 0, 12, 10),20LL);
    }
    {
        StreetWalking theObject;
        eq(3, theObject.minTime(25, 18, 7, 11),247LL);
    }
    {
        StreetWalking theObject;
        eq(4, theObject.minTime(24, 16, 12, 10),240LL);
    }
    {
        StreetWalking theObject;
        eq(5, theObject.minTime(10000000, 50000000, 800, 901),41010000000LL);
    }
    {
        StreetWalking theObject;
        eq(6, theObject.minTime(135, 122, 43, 29),3929LL);
    }
    return 0;
}
// END CUT HERE

