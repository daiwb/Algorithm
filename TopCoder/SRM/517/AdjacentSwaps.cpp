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
#define MOD 1000000007

LL mm[55][55];
LL cc[55][55];
int n;

void init() {
    cc[0][0] = 1;
    FOR(i,1,n) {
        cc[i][0] = cc[i][i] = 1;
        cc[i][1] = cc[i][i - 1] = i;
        FOR(j,2,i-1) {
            cc[i][j] = (cc[i - 1][j] + cc[i - 1][j - 1]) % MOD;
        }
    }
}

class AdjacentSwaps {
public:
    int theCount(vector <int> p) {
        n = p.size();
        init();

        REP(i,n) mm[i][i] = 1;
        REP(i,n-1) mm[i][i + 1] = (p[i] > p[i + 1]);
        FOR(d,2,n-1) {
            REP(fr,n-d) {
                int to = fr + d;
                
                vector<pair<int, int> > tt;
                FOR(i,fr,to) tt.push_back(make_pair(p[i], i - fr));
                sort(tt.begin(), tt.end());

                int len = to - fr + 1;
                vector<int> ss(len);
                REP(i,len) ss[tt[i].second] = i;

                mm[fr][to] = 0;
                FOR(i,0,len-2) {
                    int a = i, b = i + 1;
                    bool fl = true;
                    FOR(j,0,i) {
                        if ((ss[j] == a) || (ss[j] > b)) {
                            fl = false;
                            break;
                        }
                    }
                    if (fl) {
                        LL tp1 = mm[fr][fr + i];
                        LL tp2 = mm[fr + i + 1][to];
            
                        if (tp1 == 0 || tp2 == 0) continue;
            
                        LL tmp = (tp1 * tp2) % MOD;
                        tmp = (tmp * cc[to - fr - 1][i]) % MOD;
                        mm[fr][to] = (mm[fr][to] + tmp) % MOD;
                    }
                }
            }
        }
        
        return mm[0][n - 1];
    }
};

// BEGIN CUT HERE
int main() {
    {
        int pARRAY[] = {2, 0, 4, 1, 7, 3, 5, 8, 10, 6, 12, 9, 14, 11, 18, 13, 15, 16, 19, 20, 21, 23, 17, 24, 26, 22, 28, 25, 30, 27, 32, 29, 35, 31, 33, 38, 34, 36, 42, 37, 39, 40, 45, 41, 43, 46, 48, 44, 49, 47};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        AdjacentSwaps theObject;
        eq(2, theObject.theCount(p),441399938);
    }
    {
        int pARRAY[] = {1, 2, 0};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        AdjacentSwaps theObject;
        eq(0, theObject.theCount(p),1);
    }
    {
        int pARRAY[] = {0, 1};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        AdjacentSwaps theObject;
        eq(1, theObject.theCount(p),0);
    }
    {
        int pARRAY[] = {2, 0, 3, 1};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        AdjacentSwaps theObject;
        eq(2, theObject.theCount(p),2);
    }
    {
        int pARRAY[] = {1, 0, 3, 2};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        AdjacentSwaps theObject;
        eq(3, theObject.theCount(p),0);
    }
    {
        int pARRAY[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        AdjacentSwaps theObject;
        eq(4, theObject.theCount(p),716743312);
    }
    return 0;
}
// END CUT HERE
