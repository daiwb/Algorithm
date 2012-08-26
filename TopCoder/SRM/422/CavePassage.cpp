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

#define MAXN 13
#define INF 1000000000

class state {
public:
    int mp, mask, dist;
    state(int _mp, int _mask, int _dist) : mp(_mp), mask(_mask), dist(_dist) {};
    bool operator<(const state &rhs) const {
        return dist > rhs.dist;
    }
};

int n, bs, full, gt[1 << MAXN], mm[2][1 << MAXN];
vector<int> weight, tt;
vector<string> trust;
priority_queue <state> pq;

void init() {
    memset(gt, 0, sizeof(gt));
    gt[0] = INF;
    FOR(m,1,full) {
        int wtot = 0;
        REP(i,n) if (m & 1 << i) {
            wtot += weight[i];
            gt[m] = max(gt[m], tt[i]);
        }
        if (wtot > bs) gt[m] = INF;
        if (m & (m - 1)) {
            bool fl = true;
            REP(i,n) if (m & 1 << i) {
                int mk = false;
                REP(j,n) if ((m & 1 << j) && i != j && trust[i][j] == 'Y') {
                    mk = true;
                    break;
                }
                if (!mk) {
                    fl = false;
                    break;
                }
            }
            if (!fl) gt[m] = INF;
        }
    }
}

int doit() {
    memset(mm, 127, sizeof(mm));
    mm[0][full] = 0;
    pq.push(state(0, full, 0));
    while (!pq.empty()) {
        state cur = pq.top(); pq.pop();
        int dist = cur.dist, mp = cur.mp, mask = cur.mask;
        if (dist > mm[mp][mask]) continue;
        int s = mp == 0 ? mask : (mask ^ full);
        for (int m = s; m > 0; m = m - 1 & s) {
            if (dist + gt[m] < mm[1 - mp][mask ^ m]) {
                mm[1 - mp][mask ^ m] = dist + gt[m];
                pq.push(state(1 - mp, mask ^ m, mm[1 - mp][mask ^ m]));
            }
        }
    }
    return mm[1][0] < INF ? mm [1][0] : -1;
}

class CavePassage {
public:
    int minimalTime(vector<int> travelersWeights, vector<int> travelersTimes, vector<string> trustTable, int bridgeStrength)
    {
        n = travelersWeights.size();
        full = (1 << n) - 1;
        bs = bridgeStrength;
        weight = travelersWeights;
        tt = travelersTimes;
        trust = trustTable;

        init();
        return doit();
    }
};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int travelersWeightsARRAY[] = { 3,3,6 };
        vector <int> travelersWeights( travelersWeightsARRAY, travelersWeightsARRAY+ARRSIZE(travelersWeightsARRAY) );
        int travelersTimesARRAY[] = { 1,1,1 };
        vector <int> travelersTimes( travelersTimesARRAY, travelersTimesARRAY+ARRSIZE(travelersTimesARRAY) );
        string trustTableARRAY[] = {
            "YYYY", "YYY", "YYY" };
        vector <string> trustTable( trustTableARRAY, trustTableARRAY+ARRSIZE(trustTableARRAY) );
        CavePassage theObject;
        eq(3, theObject.minimalTime(travelersWeights, travelersTimes, trustTable, 6),5);
    }
    {
        int travelersWeightsARRAY[] = { 1, 1, 1 };
        vector <int> travelersWeights( travelersWeightsARRAY, travelersWeightsARRAY+ARRSIZE(travelersWeightsARRAY) );
        int travelersTimesARRAY[] = { 2, 3, 4 };
        vector <int> travelersTimes( travelersTimesARRAY, travelersTimesARRAY+ARRSIZE(travelersTimesARRAY) );
        string trustTableARRAY[] = { "YYY", "YYY", "YYY" };
        vector <string> trustTable( trustTableARRAY, trustTableARRAY+ARRSIZE(trustTableARRAY) );
        CavePassage theObject;
        eq(0, theObject.minimalTime(travelersWeights, travelersTimes, trustTable, 2),9);
    }
    {
        int travelersWeightsARRAY[] = { 1, 1, 1 };
        vector <int> travelersWeights( travelersWeightsARRAY, travelersWeightsARRAY+ARRSIZE(travelersWeightsARRAY) );
        int travelersTimesARRAY[] = { 2, 3, 4 };
        vector <int> travelersTimes( travelersTimesARRAY, travelersTimesARRAY+ARRSIZE(travelersTimesARRAY) );
        string trustTableARRAY[] = { "YYY", "YYY", "NYY" };
        vector <string> trustTable( trustTableARRAY, trustTableARRAY+ARRSIZE(trustTableARRAY) );
        CavePassage theObject;
        eq(1, theObject.minimalTime(travelersWeights, travelersTimes, trustTable, 2),10);
    }
    {
        int travelersWeightsARRAY[] = { 1, 1, 1 };
        vector <int> travelersWeights( travelersWeightsARRAY, travelersWeightsARRAY+ARRSIZE(travelersWeightsARRAY) );
        int travelersTimesARRAY[] = { 7, 13, 19 };
        vector <int> travelersTimes( travelersTimesARRAY, travelersTimesARRAY+ARRSIZE(travelersTimesARRAY) );
        string trustTableARRAY[] = { "YYN", "NYY", "YNY" };
        vector <string> trustTable( trustTableARRAY, trustTableARRAY+ARRSIZE(trustTableARRAY) );
        CavePassage theObject;
        eq(2, theObject.minimalTime(travelersWeights, travelersTimes, trustTable, 3),19);
    }
    {
        int travelersWeightsARRAY[] = { 43 };
        vector <int> travelersWeights( travelersWeightsARRAY, travelersWeightsARRAY+ARRSIZE(travelersWeightsARRAY) );
        int travelersTimesARRAY[] = { 23 };
        vector <int> travelersTimes( travelersTimesARRAY, travelersTimesARRAY+ARRSIZE(travelersTimesARRAY) );
        string trustTableARRAY[] = { "Y" };
        vector <string> trustTable( trustTableARRAY, trustTableARRAY+ARRSIZE(trustTableARRAY) );
        CavePassage theObject;
        eq(3, theObject.minimalTime(travelersWeights, travelersTimes, trustTable, 42),-1);
    }
    {
        int travelersWeightsARRAY[] = { 2,1,1,2,1,1 };
        vector <int> travelersWeights( travelersWeightsARRAY, travelersWeightsARRAY+ARRSIZE(travelersWeightsARRAY) );
        int travelersTimesARRAY[] = { 1,2,2,3,6,6 };
        vector <int> travelersTimes( travelersTimesARRAY, travelersTimesARRAY+ARRSIZE(travelersTimesARRAY) );
        string trustTableARRAY[] = {
            "YYYYNN", "YYYNNY", "YYYNYN", "YNNYNN", "NNYNYN", "NYNNNY" };
        vector <string> trustTable( trustTableARRAY, trustTableARRAY+ARRSIZE(trustTableARRAY) );
        CavePassage theObject;
        eq(3, theObject.minimalTime(travelersWeights, travelersTimes, trustTable, 4),14);
    }
    return 0;
}
// END CUT HERE
