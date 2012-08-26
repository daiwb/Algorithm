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
#define PB push_back
#define MP make_pair
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

class PermutationSignature {
public:
    vector <int> reconstruct(string str) {
        int n = str.length();
        vector <int> res;
        res.push_back(1);
        REP(i,n) {
            int now = i + 2;
            res.push_back(now);
            int sz = res.size();
            RFOR(j,i,0) {
                if (str[j] == 'D') {
                    swap(res[sz - 1], res[sz - 2]);
                    --sz;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int retrunValueARRAY[] = {1, 4, 3, 2, 7, 6, 5, 11, 10, 9, 8, 12, 14, 13, 15, 17, 16, 18, 20, 19, 22, 21, 25, 24, 23};
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(0, theObject.reconstruct("IDDIDDIDDDIIDIIDIIDIDIDD"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {1, 2, 5, 4, 3, 9, 8, 7, 6, 10, 12, 11, 14, 13, 17, 16, 15};
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(0, theObject.reconstruct("IIDDIDDDIIDIDIDD"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {3, 2, 1, 6, 5, 4, 8, 7, 9};
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(0, theObject.reconstruct("DDIDDIDI"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {6, 5, 4, 3, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(0, theObject.reconstruct("DDDDD"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {1, 2, 3, 4, 5, 6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(0, theObject.reconstruct("IIIII"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {2, 1, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(1, theObject.reconstruct("DI"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {1, 2, 3, 4, 6, 5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(2, theObject.reconstruct("IIIID"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {2, 1, 3, 5, 4, 7, 6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationSignature theObject;
        eq(3, theObject.reconstruct("DIIDID"),retrunValue);
    }
    return 0;
}
// END CUT HERE
