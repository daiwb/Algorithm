// by natalia@TopCoder
// http://www.topcoder.com/stat?c=problem_solution&rd=14147&pm=8404&cr=22651110

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

#define MAXN 105
#define inf 1000000000
typedef int elem_t;

int mat[MAXN][MAXN];
int d[MAXN], used[MAXN];
int r[5005];
vector<string> paths;
int n, m;

struct Edge {
    int u, v, w;
};

Edge e[5005];

void delEdge(int idx) {
    REP(i,MAXN) REP(j,MAXN) mat[i][j] = inf;
    REP(i,m) {
        if (i == idx) continue;
        int u = e[i].u, v = e[i].v, w = e[i].w;
        mat[u][v] = min(mat[u][v], w);
    }

    REP(i,n) d[i] = inf;
    memset(used, 0, sizeof(used));
    d[e[idx].u] = 0;

    while (true) {
        int p = -1;
        REP(i,n) {
            if (used[i]) continue;
            if (p == -1 || d[p] > d[i]) p = i;
        }

        if (p == -1 || d[p] == inf) break;

        used[p] = true;
        REP(i,n) {
            d[i] = min(d[i], d[p] + mat[p][i]);
        }
    }

    r[idx] = d[1];
}

class WarTransportation {
public:
    int messenger(int n, vector <string> highways) {
        ::n = n;
        string str = "";
        REP(i,highways.size()) str += highways[i];
        paths = split(str, ",");
        m = paths.size();
        REP(i,m) {
            stringstream ss(paths[i]);
            ss >> e[i].u >> e[i].v >> e[i].w;
            --e[i].u, --e[i].v;
        }

        REP(i,m) delEdge(i);

        REP(i,n) d[i] = inf;
        d[1] = 0;

        REP(it,n) {
            REP(i,m) {
                int u = e[i].u, v = e[i].v, w = e[i].w;
                if (d[v] == inf) continue;
                d[u] = min(d[u], max(d[v] + w, r[i]));
            }
        }

        if (d[0] == inf) return -1;
        return d[0];
    }

};
// BEGIN CUT HERE
int main() {
    {
        string highwaysARRAY[] = {"1 2 1,1 3 2,3 2 3"};
        vector <string> highways( highwaysARRAY, highwaysARRAY+ARRSIZE(highwaysARRAY) );
        WarTransportation theObject;
        eq(0, theObject.messenger(3, highways),5);
    }
    {
        string highwaysARRAY[] = {"1 3 1,1 4 1,3 5 1,4 5 1,5 6 1,6 7 1,6 8 1,7 2 1,",
            "8 2 1"};
        vector <string> highways( highwaysARRAY, highwaysARRAY+ARRSIZE(highwaysARRAY) );
        WarTransportation theObject;
        eq(1, theObject.messenger(8, highways),-1);
    }
    {
        string highwaysARRAY[] = {"1 3 1,1 3 2,3 2 1,1 4 1,4 2 1"};
        vector <string> highways( highwaysARRAY, highwaysARRAY+ARRSIZE(highwaysARRAY) );
        WarTransportation theObject;
        eq(2, theObject.messenger(4, highways),-1);
    }
    {
        string highwaysARRAY[] = {"1 3 1,3 2 1,1 4 1,4 2 1,3 4 1"};
        vector <string> highways( highwaysARRAY, highwaysARRAY+ARRSIZE(highwaysARRAY) );
        WarTransportation theObject;
        eq(3, theObject.messenger(4, highways),3);
    }
    {
        string highwaysARRAY[] = {"1 13 3,13 4 7,4 3 4,3 10 8,10 18 9,18 12 6,12 2 3,",
            "1 17 6,17 13 6,13 9 4,9 10 8,10 7 2,7 5 5,5 19 9,1",
            "9 14 6,14 16 9,16 18 7,18 15 5,15 20 3,20 12 9,12 ",
            "8 4,8 11 3,11 4 1,4 3 7,3 2 3,20 10 2,1 18 2,16 19",
            " 9,4 15 9,13 15 6"};
        vector <string> highways( highwaysARRAY, highwaysARRAY+ARRSIZE(highwaysARRAY) );
        WarTransportation theObject;
        eq(4, theObject.messenger(20, highways),23);
    }
    return 0;
}
// END CUT HERE
