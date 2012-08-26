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

class HanoiGoodAndBad {
public:
    int moves(int N, int Dave) {
        vector<int> pos(N, 0), from(N);
        init(N, Dave, pos, 0, 1, 2);
        return doit(N, from, pos, 0, 1, 2);
    }
    int doit(int n, vector<int>& from, vector<int>& to, int source, int target, int spare) {
        if (n == 0) return 0;
        if (to[n - 1] == source) return doit(n - 1, from, to, source, target, spare);
        else if (to[n - 1] == spare) {
            REP(i,n-1) from[i] = target;
            from[n - 1] = spare;
            return (int) pow(3.0, n - 1) + doit(n - 1, from, to, target, source, spare);
        } else {
            from[n - 1] = target;
            return 2 * (int) pow(3.0, n - 1) + doit(n - 1, from, to, source, target, spare);
        }
    }
    void init(int n, int steps, vector<int>& pos, int source, int target, int spare) {
        if (steps == 0) return;
        if (steps >= (1 << (n - 1)) - 1) {
            REP(i,n-1) pos[i] = spare;
            steps -= (1 << (n - 1)) - 1;
            if (steps >= 1) {
                pos[n - 1] = target;
                if (steps > 1) init(n - 1, steps - 1, pos, spare, target, source);
            }
        } else {
            init(n - 1, steps, pos, source, spare, target);
        }
    }
};
// BEGIN CUT HERE
int main() {
    {
        HanoiGoodAndBad theObject;
        eq(0, theObject.moves(3, 1),2);
    }
    {
        HanoiGoodAndBad theObject;
        eq(1, theObject.moves(4, 15),80);
    }
    {
        HanoiGoodAndBad theObject;
        eq(2, theObject.moves(9, 265),16418);
    }
    return 0;
}
// END CUT HERE
