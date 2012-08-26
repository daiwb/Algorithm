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

#define MAX_SETS 352716 // C(21, 11)
#define ALL 21
#define HALF 11

string ALPHABET = "ABCDEFZHIKLMNOPQRSTVX";
int cnts[1 << ALL];
int sets[MAX_SETS];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int mm[25][25];
int total, w, h;

class AlphabetPaths {
public:
    void backtrack(int x, int y, int state, int n) {
        int c = mm[x][y];
        if (c == -1) return;
        if (state & (1 << c)) return;
        int ns = state | (1 << c);
        if (n + 1 == HALF) {
            if (cnts[ns] == 0) sets[total++] = ns;
            cnts[ns]++;
        } else {
            REP(i,4) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                    backtrack(nx, ny, ns, n + 1);
                }
            }
        }
    }
    
    long long count(vector <string> letterMaze) {
        w = letterMaze.size();
        h = letterMaze[0].length();
        REP(i,w) {
            REP(j,h) {
                mm[i][j] = ALPHABET.find(letterMaze[i][j]);
            }
        }
        LL res = 0;
        REP(x,w) {
            REP(y,h) {
                int c = mm[x][y];
                if (c == -1) continue;
                int b = (1 << c);
                total = 0;
                backtrack(x, y, 0, 0);
                REP(i,total) {
                    int s = sets[i];
                    int cmp = ((((1 << ALL) - 1) & ~s) | b);
                    res += cnts[s] * (LL) cnts[cmp];
                }
                REP(i,total) {
                    cnts[sets[i]] = 0;
                }
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string letterMazeARRAY[] = {"ABCDEFZHIXKLMNOPQRST",
                                    "...................V"};
        vector <string> letterMaze( letterMazeARRAY, letterMazeARRAY+ARRSIZE(letterMazeARRAY) );
        AlphabetPaths theObject;
        eq(0, theObject.count(letterMaze),2LL);
    }
    {
        string letterMazeARRAY[] = {".................VT.",
                                    "....................",
                                    "ABCDEFZHIXKLMNOPQRS.",
                                    "..................S.",
                                    ".................VT."};
        vector <string> letterMaze( letterMazeARRAY, letterMazeARRAY+ARRSIZE(letterMazeARRAY) );
        AlphabetPaths theObject;
        eq(1, theObject.count(letterMaze),0LL);
    }
    {
        string letterMazeARRAY[] = {"TBCDE.PQRSA", 
                                    "FZHIXKLMNOV"};
        vector <string> letterMaze( letterMazeARRAY, letterMazeARRAY+ARRSIZE(letterMazeARRAY) );
        AlphabetPaths theObject;
        eq(2, theObject.count(letterMaze),50LL);
    }
    {
        string letterMazeARRAY[] = {"ABCDEF.",
                                    "V....Z.",
                                    "T....H.",
                                    "S....I.",
                                    "R....X.",
                                    "KLMNOPQ"};
        vector <string> letterMaze( letterMazeARRAY, letterMazeARRAY+ARRSIZE(letterMazeARRAY) );
        AlphabetPaths theObject;
        eq(3, theObject.count(letterMaze),4LL);
    }
    return 0;
}
// END CUT HERE
