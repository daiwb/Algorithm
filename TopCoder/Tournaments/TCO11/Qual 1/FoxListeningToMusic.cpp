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
class FoxListeningToMusic {
public:
    vector <double> getProbabilities(vector <int> len, int T) {
        vector<double> p(T + 1, 0.0);
        int n = len.size();
        vector<double> res(n, 0.0);
        p[0] = 1.0;
        FOR(s,1,T) {
            REP(i,n) {
                if (len[i] <= s) p[s] += p[s - len[i]] / n;
            }
        }
        REP(i,n) {
            FOR(j,0,len[i]-1) {
                if (j > T) break;
                res[i] += p[T - j] / n;
            }
        }
        return res;
    }
};

// BEGIN CUT HERE
int main() {
    {
        int lengthARRAY[] = {1, 2};
        vector <int> length( lengthARRAY, lengthARRAY+ARRSIZE(lengthARRAY) );
        double retrunValueARRAY[] = {0.25, 0.75 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxListeningToMusic theObject;
        eq(0, theObject.getProbabilities(length, 1),retrunValue);
    }
    {
        int lengthARRAY[] = {1, 10, 100, 1000, 10000};
        vector <int> length( lengthARRAY, lengthARRAY+ARRSIZE(lengthARRAY) );
        double retrunValueARRAY[] = {0.2, 0.2, 0.2, 0.2, 0.2 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxListeningToMusic theObject;
        eq(1, theObject.getProbabilities(length, 0),retrunValue);
    }
    {
        int lengthARRAY[] = {5, 8, 4, 7};
        vector <int> length( lengthARRAY, lengthARRAY+ARRSIZE(lengthARRAY) );
        double retrunValueARRAY[] = {0.1875, 0.3125, 0.1875, 0.3125 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxListeningToMusic theObject;
        eq(2, theObject.getProbabilities(length, 10),retrunValue);
    }
    {
        int lengthARRAY[] = {10, 1};
        vector <int> length( lengthARRAY, lengthARRAY+ARRSIZE(lengthARRAY) );
        double retrunValueARRAY[] = {0.9990234375, 9.765625E-4 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxListeningToMusic theObject;
        eq(3, theObject.getProbabilities(length, 9),retrunValue);
    }
    {
        int lengthARRAY[] = {58, 47, 36, 25, 14, 3};
        vector <int> length( lengthARRAY, lengthARRAY+ARRSIZE(lengthARRAY) );
        double retrunValueARRAY[] = {0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895, 0.07518634032025856, 0.017071269542683242 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxListeningToMusic theObject;
        eq(4, theObject.getProbabilities(length, 100),retrunValue);
    }
    {
        int lengthARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 80001};
        vector <int> length( lengthARRAY, lengthARRAY+ARRSIZE(lengthARRAY) );
        double retrunValueARRAY[] = {1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 1.2E-322, 0.9999999999999991};
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxListeningToMusic theObject;
        eq(4, theObject.getProbabilities(length, 80000),retrunValue);
    }
    return 0;
}
// END CUT HERE
