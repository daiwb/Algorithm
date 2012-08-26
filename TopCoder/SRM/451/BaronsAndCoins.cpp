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

int mm[55][10005];
int n;
int xx[55], yy[55];

int dp(int now, int step) {
    int& ret = mm[now][step];
    if (ret != -1) return ret;

    ret = 1;

    FOR(i,now+1,n-1) {
        int dx = xx[i] - xx[now];
        int dy = yy[i] - yy[now];

        if (dy == 0) continue;
        if (dx <= 0) continue;

        int start = step + 1;
        int sum = (start + start + dy - 1) * dy / 2;
        if (sum > dx) continue;

        int df = dx - sum;

        int nstep = (df + dy - 1) / dy + start + dy - 1;

        int t = 1 + dp(i, nstep);
        ret = max(ret, t);
    }

    return ret;
}

class BaronsAndCoins {
public:
    int getMaximum(vector <int> x, vector <int> y) {
        vector<pair<int, int> > ps;

        n = x.size();
        REP(i,n) ps.push_back(make_pair(y[i], x[i]));
        sort(ps.begin(), ps.end());
        REP(i,n) xx[i] = ps[i].second, yy[i] = ps[i].first;

        memset(mm, -1, sizeof(mm));
        int res = 0;
        REP(i,n) {
            int sum = (yy[i] + 1) * yy[i] / 2;
            if (sum > xx[i]) continue;

            int df = xx[i] - sum;
            int step = (df + yy[i] - 1) / yy[i] + yy[i];

            int t = dp(i, step);

            res = max(res, t);
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int xARRAY[] = {3191, 9143, 8981, 9694, 15, 7076, 7708, 8182, 4225, 6492, 3910, 8608, 5298, 5569, 2432, 7674, 8470, 5151, 7620, 3880, 1700, 5518, 5938, 5531, 6265, 8794, 8656, 60, 1826, 3485, 7826, 4918, 6006, 4399, 6583, 9554, 4163, 9328, 6074, 3478, 9805, 7671, 3240, 7676, 367, 9024};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {17, 28, 28, 29, 1, 26, 26, 28, 20, 24, 19, 27, 22, 22, 15, 26, 27, 22, 26, 19, 12, 23, 23, 23, 24, 28, 28, 2, 13, 18, 26, 21, 23, 20, 24, 29, 20, 28, 23, 18, 29, 26, 17, 26, 5, 29};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        BaronsAndCoins theObject;
        eq(0, theObject.getMaximum(x, y),14);
    }
    {
        int xARRAY[] = {15, 5, 30};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {4, 5, 6};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        BaronsAndCoins theObject;
        eq(0, theObject.getMaximum(x, y),2);
    }
    {
        int xARRAY[] = {10};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {10};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        BaronsAndCoins theObject;
        eq(1, theObject.getMaximum(x, y),0);
    }
    {
        int xARRAY[] = {1, 3, 6, 10, 15, 21};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 2, 3, 4, 5, 6};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        BaronsAndCoins theObject;
        eq(2, theObject.getMaximum(x, y),6);
    }
    {
        int xARRAY[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        BaronsAndCoins theObject;
        eq(3, theObject.getMaximum(x, y),3);
    }
    {
        int xARRAY[] = {1, 3, 6, 10, 22, 35, 50, 66};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 2, 3, 1, 2, 3, 4, 5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        BaronsAndCoins theObject;
        eq(4, theObject.getMaximum(x, y),5);
    }
    return 0;
}
// END CUT HERE
