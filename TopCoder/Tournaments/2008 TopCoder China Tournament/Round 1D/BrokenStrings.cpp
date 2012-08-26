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

class BrokenStrings {
public:
    int buyStrings(int n, vector <string> stringCosts) {
        int p = 1000000000, s = 1000000000;
        REP(i,stringCosts.size()) {
            istringstream is(stringCosts[i]);
            int _p, _s;
            is >> _p >> _s;
            p = min(p, _p);
            s = min(s, _s);
        }
        int res = 1000000000;
        int m = 0;
        if (n % 6 == 0) m = n / 6;
        else m = n / 6 + 1;
        FOR(i,0,m) {
            int t = i * p;
            if (n - i * 6 > 0) t += (n - i * 6) * s;
            res = min(res, t);
        }

        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string stringCostsARRAY[] = {"12 3",
            "15 4"};
        vector <string> stringCosts( stringCostsARRAY, stringCostsARRAY+ARRSIZE(stringCostsARRAY) );
        BrokenStrings theObject;
        eq(0, theObject.buyStrings(4, stringCosts),12);
    }
    {
        string stringCostsARRAY[] = {"12 3"};
        vector <string> stringCosts( stringCostsARRAY, stringCostsARRAY+ARRSIZE(stringCostsARRAY) );
        BrokenStrings theObject;
        eq(1, theObject.buyStrings(17, stringCosts),36);
    }
    {
        string stringCostsARRAY[] = {"10 3",
            "12 2"};
        vector <string> stringCosts( stringCostsARRAY, stringCostsARRAY+ARRSIZE(stringCostsARRAY) );
        BrokenStrings theObject;
        eq(2, theObject.buyStrings(7, stringCosts),12);
    }
    {
        string stringCostsARRAY[] = {"21 25","77 23","23 88","95 43","96 19","59 36",
            "80 13","51 24","15 8","25 61","21 22","3 9",
            "68 68","67 100","83 98","96 57"};
        vector <string> stringCosts( stringCostsARRAY, stringCostsARRAY+ARRSIZE(stringCostsARRAY) );
        BrokenStrings theObject;
        eq(3, theObject.buyStrings(9, stringCosts),6);
    }
    return 0;
}
// END CUT HERE
