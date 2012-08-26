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
int mat[55][55];
int mm[55][55];
int pre[55];

#define MAXN 55
#define inf 1000000000

int prim(int n, int mat[][MAXN],int* pre){
	int min[MAXN], ret = 0;
	int v[MAXN];
    REP(i,n) {
		min[i] = inf, v[i] = 0, pre[i] = -1;
    }
    min[0] = 0;
	REP(j,n) {
        int k = -1;
        REP(i,n) {
			if (!v[i] && (k == -1 || min[i] < min[k])) k = i;
        }
        v[k] = 1, ret += min[k];
        REP(i,n) {
			if (!v[i] && mat[k][i] < min[i]) min[i] = mat[pre[i] = k][i];
        }
	}
	return ret;
}

class FreeGuitars {
public:
    int minimumCosts(int N, vector <string> trainRoutes) {
        REP(i,N) {
            REP(j,N) {
                mat[i][j] = inf;
            }
        }
        memset(mm, 0, sizeof(mm));
        REP(i,trainRoutes.size()) {
            istringstream is(trainRoutes[i]);
            int i1, i2, c;
            is >> i1 >> i2 >> c;
            --i1, --i2;
            mat[i1][i2] = mat[i2][i1] = c;
            mm[i1][i2] = mm[i2][i1] = 1;
        }
        REP(k,N) {
            REP(i,N) {
                REP(j,N) {
                    if (mm[i][k] == 1 && mm[k][j] == 1) mm[i][j] = 1;
                }
            }
        }
        REP(i,N) {
            REP(j,N) {
                if (i == j) continue;
                if (mm[i][j] == 0) return -1;
            }
        }
        int res = prim(N, mat, pre);
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string trainRoutesARRAY[] = {"1 2 6", "1 3 4", "2 3 1"};
        vector <string> trainRoutes( trainRoutesARRAY, trainRoutesARRAY+ARRSIZE(trainRoutesARRAY) );
        FreeGuitars theObject;
        eq(0, theObject.minimumCosts(3, trainRoutes),5);
    }
    {
        string trainRoutesARRAY[] = {"1 3 56"};
        vector <string> trainRoutes( trainRoutesARRAY, trainRoutesARRAY+ARRSIZE(trainRoutesARRAY) );
        FreeGuitars theObject;
        eq(1, theObject.minimumCosts(3, trainRoutes),-1);
    }
    {
        string trainRoutesARRAY[] = {"1 2 88",
           "1 3 37",
           "1 4 73",
           "1 5 58",
           "2 3 59",
           "2 4 30",
           "2 5 98",
           "3 4 28",
           "3 5 85",
           "4 5 82"};
        vector <string> trainRoutes( trainRoutesARRAY, trainRoutesARRAY+ARRSIZE(trainRoutesARRAY) );
        FreeGuitars theObject;
        eq(2, theObject.minimumCosts(5, trainRoutes),153);
    }
    {
        string trainRoutesARRAY[] = {"12 2 90", "14 4 11", "6 4 18", "5 8 35", "7 13 54", "11 2 33", "12 5 52",
            "13 2 98", "10 3 3", "4 7 63", "15 11 46", "11 7 4", "11 6 24", "9 7 30",
            "13 12 19", "5 10 82", "9 1 94", "13 3 30", "11 5 12", "10 1 10", "6 9 74",
            "12 8 55", "4 11 3", "12 4 71", "9 10 90"};
        vector <string> trainRoutes( trainRoutesARRAY, trainRoutesARRAY+ARRSIZE(trainRoutesARRAY) );
        FreeGuitars theObject;
        eq(3, theObject.minimumCosts(15, trainRoutes),306);
    }
    return 0;
}
// END CUT HERE
