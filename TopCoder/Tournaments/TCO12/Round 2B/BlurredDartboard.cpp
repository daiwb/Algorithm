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

int v[55];

class BlurredDartboard {
public:
    int minThrows(vector <int> pts, int P) {
        int n = pts.size(), mx = -1, cnt = 0, sum = 0;
        memset(v, 0, sizeof(v));
        REP(i,n) {
            if (pts[i] > 0) {
                v[pts[i]] = 1;
                ++cnt;
                mx = max(mx, pts[i]);
                sum += pts[i];
            }
        }

        int total = (n + 1) * n / 2;

        int res = P;
        if (cnt == 0) {
            int ct = P / total;
            int tmp = P - ct * total;
            res = ct * n;
            FOR(i,1,n) {
                if (tmp <= 0) break;
                ++res;
                tmp -= i;
            }
        } else if (cnt == n) {
            res = (P + mx - 1) / mx;
        } else {
            int lt = total - sum;
            int ln = n - cnt;
            if (lt < ln * mx) {
                res = (P + mx - 1) / mx;
            } else {
                int ct = P / lt;
                int tmp = P - ct * lt;
                res = ct * ln;
                if (tmp > 0) {
                    int c1 = (tmp + mx - 1) / mx;
                    int c2 = 0;
                    FOR(i,1,n) {
                        if (v[i] == 1) continue;
                        tmp -= i;
                        ++c2;
                        if (tmp <= 0) break;
                    }
                    res += min(c1, c2);
                }
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int ptsARRAY[] = {0};
        vector <int> pts( ptsARRAY, ptsARRAY+ARRSIZE(ptsARRAY) );
        BlurredDartboard theObject;
        eq(0, theObject.minThrows(pts, 10),10);
    }
    {
        int ptsARRAY[] = {1};
        vector <int> pts( ptsARRAY, ptsARRAY+ARRSIZE(ptsARRAY) );
        BlurredDartboard theObject;
        eq(0, theObject.minThrows(pts, 10),10);
    }
    {
        int ptsARRAY[] = {0, 3, 4, 0, 0};
        vector <int> pts( ptsARRAY, ptsARRAY+ARRSIZE(ptsARRAY) );
        BlurredDartboard theObject;
        eq(0, theObject.minThrows(pts, 8),2);
    }
    {
        int ptsARRAY[] = {0, 0, 0, 0, 0};
        vector <int> pts( ptsARRAY, ptsARRAY+ARRSIZE(ptsARRAY) );
        BlurredDartboard theObject;
        eq(1, theObject.minThrows(pts, 15),5);
    }
    {
        int ptsARRAY[] = {4, 7, 8, 1, 3, 2, 6, 5};
        vector <int> pts( ptsARRAY, ptsARRAY+ARRSIZE(ptsARRAY) );
        BlurredDartboard theObject;
        eq(2, theObject.minThrows(pts, 2012),252);
    }
    {
        int ptsARRAY[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
        vector <int> pts( ptsARRAY, ptsARRAY+ARRSIZE(ptsARRAY) );
        BlurredDartboard theObject;
        eq(3, theObject.minThrows(pts, 2012),307);
    }
    {
        int ptsARRAY[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
        vector <int> pts( ptsARRAY, ptsARRAY+ARRSIZE(ptsARRAY) );
        BlurredDartboard theObject;
        eq(4, theObject.minThrows(pts, 1000000000),84656087);
    }
    return 0;
}
// END CUT HERE
