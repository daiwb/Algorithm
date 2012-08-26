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

// END CUT HERE
string i2s(LL n) {
    string res = "";
    do {
        res = char((n & 1) + '0') + res;
        n >>= 1;
    } while (n > 0);
    return res;
}

class BinaryCards {
public:
    long long largestNumber(long long A, long long B) {
        string s1 = i2s(A);
        string s2 = i2s(B);

        int len = s2.length();

        if (len == 1) {
            if (B == 1) return 1;
            else return 0;
        }

        if (s2.size() > s1.size()) {
            LL res = (1LL << len) - 1;
            return res;
        }

        LL res = (1LL << (len - 1));
        LL ta = (A & ~(1LL << (len - 1)));
        LL tb = (B & ~(1LL << (len - 1)));
        res += largestNumber(ta, tb);
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        BinaryCards theObject;
        eq(0, theObject.largestNumber(1L, 1000000000000000000L),1152921504606846975LL);
    }
    {
        BinaryCards theObject;
        eq(0, theObject.largestNumber(6L, 6L),6LL);
    }
    {
        BinaryCards theObject;
        eq(1, theObject.largestNumber(6L, 7L),7LL);
    }
    {
        BinaryCards theObject;
        eq(2, theObject.largestNumber(6L, 8L),15LL);
    }
    {
        BinaryCards theObject;
        eq(3, theObject.largestNumber(1L, 11L),15LL);
    }
    {
        BinaryCards theObject;
        eq(4, theObject.largestNumber(35L, 38L),39LL);
    }
    {
        BinaryCards theObject;
        eq(5, theObject.largestNumber(1125899906842630L, 1125899906842632L),1125899906842639LL);
    }
    {
        BinaryCards theObject;
        eq(5, theObject.largestNumber(3453454L, 9838457349857439L),18014398509481983LL);
    }
    return 0;
}
// END CUT HERE
