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
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define SZ(x) x.size()
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<pair<int, int> > VPI;

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

int que[2505];

class CliqueGraph {
public:
    long long calcSum(int N, vector <int> V, vector <int> sizes) {
        VVI mm(N, VI());
        int idx = 0;
        int m = SZ(sizes);
        VVI ver(m, VI());
        REP(i,m) {
            REP(j,sizes[i]) {
                mm[V[idx]].PB(i);
                ver[i].PB(V[idx]);
                ++idx;
            }
        }
        LL res = 0;
        REP(st,N) {
            VB used(m, false);
            VI dist(N, -1);
            dist[st] = 0;
            que[0] = st;
            int head = 0, tail = 0;
            while (head <= tail) {
                int cur = que[head];
                ++head;
                REP(i,SZ(mm[cur])) {
                    int id = mm[cur][i];
                    if (used[id]) continue;
                    used[id] = true;
                    REP(j,SZ(ver[id])) {
                        int now = ver[id][j];
                        if (dist[now] != -1) continue;
                        dist[now] = dist[cur] + 1;
                        res += dist[now];
                        que[++tail] = now;
                    }
                }
            }
        }
        return res / 2;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int VARRAY[] = {0,1,2,0,3};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        int sizesARRAY[] = {3,2};
        vector <int> sizes( sizesARRAY, sizesARRAY+ARRSIZE(sizesARRAY) );
        CliqueGraph theObject;
        eq(0, theObject.calcSum(4, V, sizes),8LL);
    }
    {
        int VARRAY[] = {0,1,2,3,1,2,4};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        int sizesARRAY[] = {4,3};
        vector <int> sizes( sizesARRAY, sizesARRAY+ARRSIZE(sizesARRAY) );
        CliqueGraph theObject;
        eq(1, theObject.calcSum(5, V, sizes),12LL);
    }
    {
        int VARRAY[] = {1,3,5,7,9,11,13,0
           ,2,3,6,7,10,11,14,0
           ,4,5,6,7,12,13,14,0
           ,8,9,10,11,12,13,14,0};
        vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
        int sizesARRAY[] = {8,8,8,8};
        vector <int> sizes( sizesARRAY, sizesARRAY+ARRSIZE(sizesARRAY) );
        CliqueGraph theObject;
        eq(2, theObject.calcSum(15, V, sizes),130LL);
    }
    return 0;
}
// END CUT HERE
