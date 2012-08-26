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

bool isblack(int s, int N, int K, int r, int c) {
    if (s == 0) {
        return false;
    }
    int rr = r / N, cc = c / N;
    if (isblack(s - 1, N, K, rr, cc)) {
        return true;
    } else {
        int tr = r % N, tc = c % N;
        int gap = (N - K) / 2;
        if (tr >= gap && tr <= N - 1 - gap && tc >= gap && tc <= N - 1 - gap) {
            return true;
        } else {
            return false;
        }
    }
}

class PlaneFractal {
public:
    vector <string> getPattern(int s, int N, int K, int r1, int r2, int c1, int c2) {
        vector <string> res;
        FOR(r,r1,r2) {
            string str = "";
            FOR(c,c1,c2) {
                if (isblack(s, N, K, r, c)) str += "1";
                else str += "0";
            }
            res.push_back(str);
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string retrunValueARRAY[] = {"00000", "01110", "01110", "01110", "00000" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlaneFractal theObject;
        eq(0, theObject.getPattern(1, 5, 3, 0, 4, 0, 4),retrunValue);
    }
    {
        string retrunValueARRAY[] = {"000000000", "010010010", "000000000", "000111000", "010111010", "000111000", "000000000", "010010010", "000000000" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlaneFractal theObject;
        eq(1, theObject.getPattern(2, 3, 1, 0, 8, 0, 8),retrunValue);
    }
    {
        string retrunValueARRAY[] = {"101001", "100000", "000000", "001001", "000000", "000011", "001011", "000011" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlaneFractal theObject;
        eq(2, theObject.getPattern(3, 3, 1, 4, 11, 5, 10),retrunValue);
    }
    {
        string retrunValueARRAY[] = {"000000000000000000000000", "000000000000000000000000", "011110000111100001111000", "011110000111100001111000", "011110000111100001111000", "011110000111100001111000" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlaneFractal theObject;
        eq(3, theObject.getPattern(2, 8, 4, 56, 61, 33, 56),retrunValue);
    }
    return 0;
}
// END CUT HERE
