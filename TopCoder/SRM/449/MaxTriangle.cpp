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

#define EPS 1e-10

class MaxTriangle {
public:
    double calculateArea(int A, int B) {
        double aa = sqrt(A + 0.0), bb = sqrt(B + 0.0);
        int m1 = (int)aa, m2 = (int)bb;

        vector<pair<int, int> > mm1, mm2;
        
        FOR(i,0,m1) {
            int c1 = i * i;
            int c2 = (int)sqrt(A - c1 + 0.0);
            if (c2 * c2 != A - c1) continue;
            mm1.push_back(make_pair(i, c2));
        }

        FOR(i,0,m2) {
            int c1 = i * i;
            int c2 = (int)sqrt(B - c1 + 0.0);
            if (c2 * c2 != B - c1) continue;
            mm2.push_back(make_pair(i, c2));
        }

        if (mm1.empty() || mm2.empty()) return -1.0;

        double res = -1.0;
        REP(i,mm1.size()) {
            REP(j,mm2.size()) {
                double x1 = mm1[i].first, y1 = mm1[i].second;
                double x2 = mm2[j].first, y2 = mm2[j].second;

                REP(ii,2) {
                    REP(jj,2) {
                        double aa1 = 1.0, bb1 = 1.0;
                        if (ii == 1) aa1 = -1.0;
                        if (jj == 1) bb1 = -1.0;

                        double cc = sqrt((x1 + x2 * aa1) * (x1 + x2 * aa1) + (y1 + y2 * bb1) * (y1 + y2 * bb1));

                        double S = (aa + bb + cc) / 2.0;
                        double area = sqrt(S * (S - aa) * (S - bb) * (S - cc));
                        area = fabs(x1 * y2 + x2 * y1) / 2.0;
                        if (area > EPS) {
                            res = max(res, area);
                        }
                    }
                }

            }
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        MaxTriangle theObject;
        eq(0, theObject.calculateArea(1, 1),0.5);
    }
    {
        MaxTriangle theObject;
        eq(1, theObject.calculateArea(3, 7),-1.0);
    }
    {
        MaxTriangle theObject;
        eq(2, theObject.calculateArea(41, 85),29.5);
    }
    return 0;
}
// END CUT HERE
