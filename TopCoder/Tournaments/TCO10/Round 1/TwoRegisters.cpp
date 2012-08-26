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

#define MAXN 1000000

class TwoRegisters {
public:
    string minProg(int r) {
        if (r == 1) return "";
        string res(MAXN, 'X');
        FOR(k,1,r-1) {
            string tmp;
            int x = r, y = k;
            bool flag = true;
            while (true) {
                if (tmp.length() >= res.length()) {
                    flag = false;
                    break;
                }

                if (x == 1 && y == 1) break;

                if (x == y || x < 1 || y < 1) {
                    flag = false;
                    break;
                }

                if (y == 1) {
                    tmp.append(x - 1, 'X');
                    break;
                }
                if (x == 1) {
                    tmp.append(y - 1, 'Y');
                    break;
                }
                
                if (x > y) {
                    tmp.append(x / y, 'X');
                    x %= y;
                } else {
                    tmp.append(y / x, 'Y');
                    y %= x;
                }
            }

            if (flag) {
                if (tmp.length() < res.length()) {
                    reverse(tmp.begin(), tmp.end());
                    res = tmp;
                } else {
                    reverse(tmp.begin(), tmp.end());
                    if (tmp.length() == res.length()) res = min(res, tmp);
                }
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        TwoRegisters theObject;
        eq(0, theObject.minProg(2),"X");
    }
    {
        TwoRegisters theObject;
        eq(0, theObject.minProg(10),"XXYYX");
    }
    {
        TwoRegisters theObject;
        eq(1, theObject.minProg(3),"XX");
    }
    {
        TwoRegisters theObject;
        eq(2, theObject.minProg(20),"XYYYYXX");
    }
    {
        TwoRegisters theObject;
        eq(3, theObject.minProg(34),"XYXYXYX");
    }
    {
        TwoRegisters theObject;
        eq(0, theObject.minProg(1000000),"XXYXYXYXXYXYXYXXYYXXYXYYXYYXYX");
    }
    return 0;
}
// END CUT HERE
