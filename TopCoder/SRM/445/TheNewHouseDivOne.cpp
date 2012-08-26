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

class TheNewHouseDivOne {
public:
    double distance(vector <int> x, vector <int> y, int k) {
        int n = x.size();
        REP(i,n) {
            x[i] *= 2;
            y[i] *= 2;
        }
        double res = 2000000000.0;
        FOR(p,-110,110) {
            FOR(q,-110,110) {
                vector<int> mm;
                REP(i,n) mm.push_back(abs(p - x[i]) + abs(q - y[i]));
                sort(mm.begin(), mm.end());
                res = min(res, mm[k - 1] + 0.0);
            }
        }
        return res / 2.0;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int xARRAY[] = {-1, -1, 1, 1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-1, 1, -1, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        TheNewHouseDivOne theObject;
        eq(0, theObject.distance(x, y, 3),2.0);
    }
    {
        int xARRAY[] = {-1, -1, 1, 1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-1, 1, -1, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        TheNewHouseDivOne theObject;
        eq(1, theObject.distance(x, y, 2),1.0);
    }
    {
        int xARRAY[] = {4, 4, 4, 4, 4, 3, 3, 5, 5};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {7, 7, 7, 4, 4, 5, 6, 5, 6};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        TheNewHouseDivOne theObject;
        eq(2, theObject.distance(x, y, 9),1.5);
    }
    {
        int xARRAY[] = {30, -15, 24, -23, 43, -8, -6, -47, 23, -11, 43, 6, -18, 44, -46, 16, 32, 31, 13, 9, 22, 25, 4, -44, 38, -41, -20, 41, -35, 7, 25, 39, -36, -20, -5, -38, -15, -22, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-45, -7, -33, 31, -8, -33, -20, -14, -50, -48, -31, 35, -24, -31, -11, 41, -41, -11, 46, -1, -5, 5, -39, -26, -40, -9, 16, 38, -30, 34, 46, -17, -27, 33, -38, 28, 46, -16, -46};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        TheNewHouseDivOne theObject;
        eq(3, theObject.distance(x, y, 13),32.0);
    }
    return 0;
}
// END CUT HERE
