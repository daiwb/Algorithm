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

class EllysRivers {
public:
    double getMin(int length, int walk, vector <int> width, vector <int> speed) {
        int n = width.size();
        vector<double> cur(length + 1);
        FOR(i,0,length) cur[i] = (length - i) * 1.0 / walk;
        RFOR(i,n-1,0) {
            vector<double> pre(length + 1);
            cur.swap(pre);
            int k = 0;
            FOR(j,0,length) {
                cur[j] = hypot(k - j, width[i]) / speed[i] + pre[k];
                while (k + 1 <= length) {
                    int t = k + 1;
                    double tmp = hypot(t - j, width[i]) / speed[i] + pre[t];
                    if (tmp < cur[j]) {
                        cur[j] = tmp;
                        ++k;
                    }
                    else break;
                }
            }
        }
        return cur[0];
    }
};
// BEGIN CUT HERE
int main() {
    {
        int widthARRAY[] = {5, 2, 3};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {5, 2, 7};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(0, theObject.getMin(10, 3, width, speed),3.231651964071508);
    }
    {
        int widthARRAY[] = {911};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {207};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(1, theObject.getMin(10000, 211, width, speed),48.24623664712219);
    }
    {
        int widthARRAY[] = {100, 200, 300, 400};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {11, 12, 13, 14};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(2, theObject.getMin(1337, 2, width, speed),128.57830549575695);
    }
    {
        int widthARRAY[] = {11, 12, 13, 14};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {100, 200, 300, 400};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(3, theObject.getMin(77, 119, width, speed),0.3842077071089629);
    }
    {
        int widthARRAY[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(4, theObject.getMin(7134, 1525, width, speed),214.6509731258811);
    }
    return 0;
}
// END CUT HERE
