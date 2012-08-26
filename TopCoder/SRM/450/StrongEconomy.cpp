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

bool isok(LL N, LL K, LL P, LL T, LL D) {
    if ((double)N * K * D >= (double)T) return true;

    --D;
    if (D <= 0) return false;

    double cur = N * K;
    while (true) {
        double rem = T - cur;
        LL rds = (LL)((rem + N * K - 1) / (N * K));

        if (rds <= D) return true;

        if (cur < P) {
            rem = P - cur;
            rds = (LL)((rem + N * K - 1) / (N * K));
            D -= rds;
            if (D < 1) return false;
            cur += rds * N * K;
        }

        cur -= P;

        if (N > K) ++K;
        else ++N;
    }

    return false;
}

class StrongEconomy {
public:
    long long earn(long long n, long long k, long long price, long long target) {
        LL left = 1, right = target;
        while (left < right) {
            LL mid = (left + right) >> 1;
            if (isok(n, k, price, target, mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};

// BEGIN CUT HERE
int main() {
    {
        StrongEconomy theObject;
        eq(0, theObject.earn(2L, 1L, 2L, 10L),4LL);
    }
    {
        StrongEconomy theObject;
        eq(1, theObject.earn(2L, 1L, 2L, 9L),3LL);
    }
    {
        StrongEconomy theObject;
        eq(2, theObject.earn(1L, 1L, 500000L, 1000002L),1000001LL);
    }
    {
        StrongEconomy theObject;
        eq(3, theObject.earn(5L, 4L, 15L, 100L),5LL);
    }
    return 0;
}
// END CUT HERE
