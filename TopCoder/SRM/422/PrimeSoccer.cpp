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
typedef long long LL; 

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

int primes[7] = {2, 3, 5, 7, 11, 13, 17};

LL C(LL n, LL m) {
    if (m > n - m) m = n - m;
    LL ret = 1;
    FOR(i,1,m) {
        ret *= (n - m + i);
        ret /= i;
    }
    return ret;
}

double doit(double p, int n) {
    double ret = C(18, n);
    REP(i,n) ret *= p;
    REP(i,18-n) ret *= (1 - p);
    return ret;
}

class PrimeSoccer {
public:
    double getProbability(int skillOfTeamA, int skillOfTeamB) {
        double pa = 0, pb = 0;
        REP(i,7) {
            pa += doit(skillOfTeamA / 100.0, primes[i]);
            pb += doit(skillOfTeamB / 100.0, primes[i]);
        }
        double res = pa + pb - pa * pb;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        PrimeSoccer theObject;
        eq(0, theObject.getProbability(50, 50),0.5265618908306351);
    }
    {
        PrimeSoccer theObject;
        eq(1, theObject.getProbability(100, 100),0.0);
    }
    {
        PrimeSoccer theObject;
        eq(2, theObject.getProbability(12, 89),0.6772047168840167);
    }
    return 0;
}
// END CUT HERE
