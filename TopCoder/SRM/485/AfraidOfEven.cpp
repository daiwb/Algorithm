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

#define MAXN 2147483647

class AfraidOfEven {
public:
    vector <int> restoreProgression(vector <int> seq) {
        vector<LL> mm;
        int len = seq.size();
        REP(i,len) mm.push_back(seq[i]);
        vector<int> res;

        for (LL a = mm[0]; ; a <<= 1) {
            for (LL b = mm[1]; b <= MAXN; b <<= 1) {
                LL diff = b - a, val = b;
                bool ok = true;
                FOR(i,2,len-1) {
                    val += diff;
                    if (val > MAXN || (val % mm[i] != 0)) {
                        ok = false;
                        break;
                    }
                    LL c = val / mm[i];
                    if (c & (c - 1)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    res.push_back(a);
                    res.push_back(b);
                    val = b;
                    FOR(i,2,len-1) {
                        val += diff;
                        res.push_back(val);
                    }
                    return res;
                }
            }
        }
        
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int seqARRAY[] = {1, 1, 3, 1, 5};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        int retrunValueARRAY[] = {1, 2, 3, 4, 5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AfraidOfEven theObject;
        eq(0, theObject.restoreProgression(seq),retrunValue);
    }
    {
        int seqARRAY[] = {9, 7, 5, 3, 1};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        int retrunValueARRAY[] = {9, 7, 5, 3, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AfraidOfEven theObject;
        eq(1, theObject.restoreProgression(seq),retrunValue);
    }
    {
        int seqARRAY[] = {999, 999, 999, 999};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        int retrunValueARRAY[] = {999, 999, 999, 999 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AfraidOfEven theObject;
        eq(2, theObject.restoreProgression(seq),retrunValue);
    }
    {
        int seqARRAY[] = {7, 47, 5, 113, 73, 179, 53};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        int retrunValueARRAY[] = {14, 47, 80, 113, 146, 179, 212 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AfraidOfEven theObject;
        eq(3, theObject.restoreProgression(seq),retrunValue);
    }
    {
        int seqARRAY[] = {749, 999, 125, 1};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        int retrunValueARRAY[] = {1498, 999, 500, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AfraidOfEven theObject;
        eq(4, theObject.restoreProgression(seq),retrunValue);
    }
    return 0;
}
// END CUT HERE
