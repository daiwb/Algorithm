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

#define INF 1000000000

class FoxAndPhotography {
public:
    vector<int> ff, bb;
    int n;
    int mm[1 << 16];
    int dp(int now, int s) {
        int& ret = mm[s];
        if (ret != -1) return ret;
        if (now == n) return ret = 0;
        ret = INF;
        int m = 0;
        REP(i,n) {
            if ((s & (1 << i)) == 0) continue;
            if (ff[i] < bb[now]) {
                int t = dp(now + 1, s - (1 << i));
                if (t != INF) ret = min(ret, t + m);
            }
            ++m;
        }
        return ret;
    }
    int getMinimumSwaps(vector <int> heightsFront, vector <int> heightsBack) {
        ff = heightsFront;
        bb = heightsBack;
        n = ff.size();
        memset(mm, -1, sizeof(mm));
        int ret = dp(0, (1 << n) - 1);
        return ret == INF ? -1 : ret;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int heightsFrontARRAY[] = {150, 146};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {148, 151};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(0, theObject.getMinimumSwaps(heightsFront, heightsBack),1);
    }
    {
        int heightsFrontARRAY[] = {140, 150};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {160, 150};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(0, theObject.getMinimumSwaps(heightsFront, heightsBack),1);
    }
    {
        int heightsFrontARRAY[] = {140, 140, 140, 140};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {190, 190, 190, 190};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(1, theObject.getMinimumSwaps(heightsFront, heightsBack),0);
    }
    {
        int heightsFrontARRAY[] = {170, 170, 170};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {160, 170, 180};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(2, theObject.getMinimumSwaps(heightsFront, heightsBack),-1);
    }
    {
        int heightsFrontARRAY[] = {140, 141, 142, 143};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {144, 143, 142, 141};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(3, theObject.getMinimumSwaps(heightsFront, heightsBack),6);
    }
    {
        int heightsFrontARRAY[] = {140, 170, 140, 170, 140, 170, 140, 170, 140, 170}
           ;
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {180, 180, 180, 180, 180, 150, 150, 150, 150, 150};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(4, theObject.getMinimumSwaps(heightsFront, heightsBack),15);
    }
    return 0;
}
// END CUT HERE
