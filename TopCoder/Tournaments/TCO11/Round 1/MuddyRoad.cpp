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
double mm[55];
double pro[55];
int vv[55];
int len;

double dp(int now) {
    double& ret = mm[now];
    if (vv[now] == 1) return ret;

    if (now == len - 1) {
        vv[now] = 1;
        return ret = 0;
    }

    ret = (1 - pro[now]) * dp(now + 1);
    if (now != len - 2) {
        ret += pro[now] * (pro[now + 1] * (1 + dp(now + 2)) + (1 - pro[now + 1]) * dp(now + 2));
    }

    vv[now] = 1;
    return ret;
}

class MuddyRoad {
public:
    double getExpectedValue(vector <int> road) {
        len = road.size();
        REP(i,len) pro[i] = road[i] / 100.0;
        
        // DP solution, O(n)
        //memset(vv, 0, sizeof(vv));
        //return dp(0);

        // Math solution, O(n^3)
        double ans = 0.0;
        REP(i,len) {
            FOR(j,i+1,len-1) {
                double p = (1 - pro[i]) * (1 - pro[j]);
                FOR(k,i+1,j-1) p *= pro[k];
                int step = ((j - i - 1) >> 1);
                ans += step * p;
            }
        }
        return ans;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int roadARRAY[] = {0, 60, 60, 0};
        vector <int> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        MuddyRoad theObject;
        eq(0, theObject.getExpectedValue(road),0.36);
    }
    {
        int roadARRAY[] = {0, 50, 50, 50, 50, 0};
        vector <int> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        MuddyRoad theObject;
        eq(1, theObject.getExpectedValue(road),0.5625);
    }
    {
        int roadARRAY[] = {0, 0, 100, 100, 100, 100, 100, 100, 0, 0, 100, 0};
        vector <int> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        MuddyRoad theObject;
        eq(2, theObject.getExpectedValue(road),3.0);
    }
    {
        int roadARRAY[] = {0, 12, 34, 56, 78, 91, 23, 45, 67, 89, 0};
        vector <int> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        MuddyRoad theObject;
        eq(3, theObject.getExpectedValue(road),1.7352539420031923);
    }
    {
        int roadARRAY[] = {0, 50, 50, 100, 50, 100, 50, 50, 100, 66, 0};
        vector <int> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        MuddyRoad theObject;
        eq(4, theObject.getExpectedValue(road),2.288125);
    }
    return 0;
}
// END CUT HERE
