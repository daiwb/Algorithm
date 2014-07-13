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
#define CLR(x) memset((x),0,sizeof((x)))
#define SORT(x) sort(x.begin(), x.end())
#define SZ(x) x.size()
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;

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
#define MAXN 1005

int n, k, res;
VVI mm;
VI val;
int used[MAXN], sum[MAXN];

void update(int idx, int v) {
    while (idx <= MAXN) {
        sum[idx] += v;
        idx += (idx & -idx);
    }
}

int total(int idx) {
    int t = 0;
    while (idx > 0) {
        t += sum[idx];
        idx -= (idx & -idx);
    }
    return t;
}

class GraphInversions {
public:
    void dfs(int cur, int num, int sum) {
        if (sum >= res) return;
        if (num >= k) {
            res = min(res, sum);
            return;
        }
        REP(i,SZ(mm[cur])) {
            int prev = mm[cur][i];
            if (used[prev] == 0) {
                used[prev] = 1;
                int cur = val[prev];
                update(cur, 1);
                int add = total(cur - 1);
                dfs(prev, num + 1, sum + add);
                used[prev] = 0;
                update(cur, -1);
            }
        }
    }
    int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
        val = V;
        k = K;
        n = SZ(A);
        mm.assign(n, VI());
        REP(i,n) {
            int a = A[i], b = B[i];
            mm[a].PB(b);
            mm[b].PB(a);
        }
        res = INF;
        REP(i,n) {
            CLR(used);
            CLR(sum);
            used[i] = 1;
            update(val[i], 1);
            dfs(i, 1, 0);
        }
        if (res == INF) return -1;
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int AARRAY[] = {0,1,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,0};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int VARRAY[] = {40,50,60};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        GraphInversions theObject;
        eq(0, theObject.getMinimumInversions(A, B, V, 3),0);
    }
    {
        int AARRAY[] = {0,1,2,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,0};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int VARRAY[] = {60,40,50,30};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        GraphInversions theObject;
        eq(1, theObject.getMinimumInversions(A, B, V, 3),1);
    }
    {
        int AARRAY[] = {0,1,2,3,0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,0,4};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int VARRAY[] = {10,10,10,5,5};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        GraphInversions theObject;
        eq(2, theObject.getMinimumInversions(A, B, V, 5),1);
    }
    {
        int AARRAY[] = {0,1,2,3,0,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,0,4,5};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int VARRAY[] = {10,2,5,3,7,1};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        GraphInversions theObject;
        eq(3, theObject.getMinimumInversions(A, B, V, 6),-1);
    }
    {
        int AARRAY[] = {5,7,7,5,5,7,6,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,0,2,0,1,4,7,3};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int VARRAY[] = {15,10,5,30,22,10,5,2};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        GraphInversions theObject;
        eq(4, theObject.getMinimumInversions(A, B, V, 6),3);
    }
    return 0;
}
// END CUT HERE
