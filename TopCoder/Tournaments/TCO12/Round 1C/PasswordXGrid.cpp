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

class PasswordXGrid {
public:
    int n, m;
    int mm[50][50];
    int minSum(vector <string> hh, vector <string> vv) {
        n = hh.size() - 1, m = hh[0].size();
        memset(mm, 0, sizeof(mm));
        FOR(i,0,n) {
            FOR(j,0,m) {
                if (i > 0) mm[i][j] = max(mm[i][j], mm[i - 1][j] + vv[i - 1][j] - '0');
                if (j > 0) mm[i][j] = max(mm[i][j], mm[i][j - 1] + hh[i][j - 1] - '0');
            }
        }
        return mm[n][m];
    }

};
// BEGIN CUT HERE
int main() {
    {
        string horizontalARRAY[] = {"1","4"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"32"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        //eq(0, theObject.minSum(horizontal, vertical),7);
    }
    {
        string horizontalARRAY[] = {"47", "59"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"361"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(1, theObject.minSum(horizontal, vertical),19);
    }
    {
        string horizontalARRAY[] = {"36", "23", "49"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"890", "176"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(2, theObject.minSum(horizontal, vertical),28);
    }
    {
        string horizontalARRAY[] = {"8888585","5888585"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"58585858"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(3, theObject.minSum(horizontal, vertical),58);
    }
    {
        string horizontalARRAY[] = {"7777777","7777777","7777777","7777777"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"44444444","44444444","44444444"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(4, theObject.minSum(horizontal, vertical),61);
    }
    return 0;
}
// END CUT HERE
