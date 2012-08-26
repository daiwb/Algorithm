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
int s2i(string s) {
    istringstream is(s); int x; is>>x; return x;
}
string i2s(int i) {
    stringstream ss; ss<<i; string x; ss>>x; return x;
}

class MirroredClock {
    public:
        string whatTimeIsIt(string time) {
	        int h = s2i(time.substr(0, 2));
	        int m = s2i(time.substr(3));
            h = (h == 0) ? 0 : 12 - h;
            m = (m == 0) ? 0 : 60 - m;
            if (m != 0) h = (h + 11) % 12;

	        string ret = "";
	        string t = i2s(h);
	        if (t.length() == 1) t = "0" + t;
	        ret += t;
	        
            ret += ":";
	        
            t = i2s(m);
	        if (t.length() == 1) t = "0" + t;
	        ret += t;
            
            return ret;
        }
};
// BEGIN CUT HERE
int main() {
    {
        MirroredClock theObject;
        eq(0, theObject.whatTimeIsIt("10:00"),"02:00");
    }
    {
        MirroredClock theObject;
        eq(1, theObject.whatTimeIsIt("01:15"),"10:45");
    }
    {
        MirroredClock theObject;
        eq(2, theObject.whatTimeIsIt("03:40"),"08:20");
    }
    {
        MirroredClock theObject;
        eq(3, theObject.whatTimeIsIt("00:00"),"00:00");
    }
    {
        MirroredClock theObject;
        eq(4, theObject.whatTimeIsIt("11:53"),"00:07");
    }
    return 0;
}
// END CUT HERE

