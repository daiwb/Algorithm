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
#define MAXN 105
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int match1[MAXN], match2[MAXN];

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

vector<int> children[MAXN];
int P;
map<int, int> mm[MAXN];

// for memoization, we use an associative array. mem[i][j] describes the
// entry for node i. Where j is the number of sub-interval of length w
// the number of sub-interval can be pretty large, hence why we do not
// use a simple array. Note each mem[i] will need at most P values in the map<int,int>

bool doable(int i, int x, int j) {
    // interval length w = 1 / x
    // Can we put node i in interval [j/x , (j+1)/x] ?

    if (mm[i].count(j) != 0) return mm[i][j];

    // A leaf.
    // make sure there is no integer k such that k/p is strictly inside interval
    bool res = false;
    if (children[i].size() == 0) {
        res = true;
        FOR(k,1,P-1) {
            // Check if ( j/x < k/P < (j+1)/x):
            if ((P * j < x * k) && (x * k < P * (j + 1))) res = false;
        }
    } else {
        int g = children[i].size();
        int can[MAXN][MAXN];
        //memset(can, 1, sizeof(can));
        REP(b,g) {
            bool nontrivial = false;

            // We want to know if a k exists such that k/P is between
            // the b-th sub-interval
            FOR(k,1,P-1) {
                // the b-th sub-interval starts at j/x  + b /gx
                // and finishes at j/x + (b+1)/gx
                // (j/x is the start of node i's interval)
                 
                // Check if ( j/x + b/gx < k/P < j/x + (b+1)/gx
                //          j*g*P + b*P  <k*g*x< j*g*P+(b+1)*P 
                if ((g * j * P + b * P < g * k * x) && (g * k * x < g * j * P + (b + 1) * P)) nontrivial = true;
            }

            if (nontrivial) {
                REP(a,g) {
                    can[a][b] = doable(children[i][a], x * g, j * g + b);
                }
            } else {
                REP(a,g) can[a][b] = true;
            }
        }
        int t = hungary(g, g, can, match1, match2);
        res = (t == g);
    }

    return (mm[i][j] = res);
}

class LotteryTree {
public:
    string isFairTree(vector <int> tree, int _P) {
        P = _P;
        REP(i,MAXN) {
            children[i].clear();
            mm[i].clear();
        }
        REP(i,tree.size()) children[tree[i]].push_back(i + 1);
        return doable(0, 1, 0) ? "YES" : "NO";
    }
};
// BEGIN CUT HERE
int main() {
    {
        int treeARRAY[] = {0, 0, 0};
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(0, theObject.isFairTree(tree, 3),"YES");
    }
    {
        int treeARRAY[] = {0, 0, 0, 1, 1, 2, 2, 3, 3};
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(1, theObject.isFairTree(tree, 2),"YES");
    }
    {
        int treeARRAY[] = {0, 0, 1, 1, 2, 2, 4, 4, 4};
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(2, theObject.isFairTree(tree, 3),"NO");
    }
    {
        int treeARRAY[] = {0, 0, 1, 1, 1, 3, 3, 3};
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(3, theObject.isFairTree(tree, 3),"NO");
    }
    {
        int treeARRAY[] = {0, 0, 0, 3, 0, 0, 3, 6, 3, 1, 0, 2, 0, 4, 6, 15, 1, 15, 11, 11, 1, 4, 11, 2, 11, 2, 6}
           ;
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(4, theObject.isFairTree(tree, 6),"YES");
    }
    {
        int treeARRAY[] = {0, 1, 2, 3, 1, 1, 4, 4, 0, 1, 6, 9, 1, 12, 9, 2, 4, 8, 6, 13, 8, 5, 11, 12, 17, 
            19, 13, 9, 3, 24, 30, 29, 28, 28, 11, 27, 2, 26, 6, 14, 8, 26, 15, 25, 33, 38, 
            1, 24, 15, 43, 3, 39, 26, 8, 13, 50, 28, 8, 6, 27, 8, 38, 27, 50, 17, 50, 25, 
            40, 7, 29, 22, 40, 2, 24, 22, 30, 33, 40, 19, 14, 26, 39, 5, 43, 7, 4};
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(5, theObject.isFairTree(tree, 9),"NO");
    }
    {
        int treeARRAY[] = {0, 1, 0, 0, 4, 0, 2, 2, 0, 2, 6, 1, 3, 6, 5, 9, 11, 13, 1, 10, 14, 4, 7, 21,
            16, 8, 25, 4, 5, 22, 25, 14, 12, 11, 12, 26, 21, 8, 2, 38, 3, 5, 4, 38, 27, 
            35, 38, 30, 38, 9, 16, 36, 6, 10, 7, 27, 30, 33, 17, 26, 17, 10, 35, 10, 38,
            41, 15, 9, 3, 27, 8, 15, 38, 22, 41, 33, 33, 36, 30, 13, 18, 22, 18};
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(6, theObject.isFairTree(tree, 12),"YES");
    }
    {
        int treeARRAY[] = {0, 0, 2, 3, 4, 3, 2, 1, 8, 6, 8, 8, 2, 7, 14, 2, 8, 1, 11, 11, 12, 16, 12, 
            19, 20, 13, 7, 12, 26, 11, 18, 19, 18, 20, 4, 9, 1, 1, 6, 16, 1, 35, 27, 24,
            37, 30, 36, 41, 32, 36, 8, 2, 6, 14, 41, 1, 35, 6, 30, 16, 12, 2, 35, 25, 50,
            13, 1, 24, 8, 32, 26, 50, 9, 19, 9, 20, 26, 27, 6, 12, 25, 9, 37, 37, 9} ;
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(7, theObject.isFairTree(tree, 7),"NO");
    }
    {
        int treeARRAY[] = {0, 0, 1, 0, 2, 3, 0, 0, 8, 5, 7, 5, 2, 12, 12, 14, 14, 13, 8, 2, 1, 7, 18,
            16, 8, 24, 18, 2, 24, 3, 11, 5, 24, 4, 34, 6, 31, 13, 38, 19, 4, 3, 22, 3,
            11, 12, 21, 34, 41, 8, 19, 4, 13, 29, 33, 8, 14, 50, 18, 45, 16, 50, 44, 50,
            38, 5, 43, 31, 29, 7, 6, 45, 38, 4, 19, 41, 50, 21, 44, 41, 43, 22, 33, 6, 8}
           ;
        vector <int> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        LotteryTree theObject;
        eq(8, theObject.isFairTree(tree, 12),"YES");
    }
    return 0;
}
// END CUT HERE
