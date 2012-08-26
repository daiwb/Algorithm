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
int doit(vector<string>& mm) {
    int r = mm.size(), c = mm[0].size();
    int res = r + c;
    REP(cur,r) {
        int mat[105][105];
        memset(mat, 0, sizeof(mat));
        bool quit = false;
        int ne = 0;
        REP(i,r) {
            if (i == cur) continue;
            char ch = '#';
            REP(j,c) {
                if (mm[cur][j] != mm[i][j]) {
                    if (ch == '#') {
                        ch = mm[i][j];
                    } else {
                        if (mm[i][j] != ch) {
                            quit = true;
                            break;
                        }
                    }
                }
            }
            if (quit) break;
            if (ch == '#') continue;
            ++ne;
            REP(j,c) {
                if (mm[i][j] != ch) {
                    mat[i][r + j] = 1;
                } else if (mm[i][j] != mm[cur][j]) {
                    mat[r + j][i] = 1;
                }
            }
        }
        if (quit) continue;
        // Check case ["AC", "DB", "AB"] for a cycle.
        int tot = r + c;
        REP(k,tot-1) {
            REP(i,tot) {
                REP(j,tot) {
                    if (mat[i][k] && mat[k][j]) mat[i][j] = 1;
                }
            }
        }
        REP(i,tot) {
            if (mat[i][i]) {
                quit = true;
                break;
            }
        }
        if (!quit) res = min(res, ne + c);
    }
    return res;
}

class ColorfulBoard {
public:
    int theMin(vector <string> board) {
        int r = board.size(), c = board[0].size();
        vector<string> tmp;
        REP(j,c) {
            string str = "";
            REP(i,r) str += board[i][j];
            tmp.push_back(str);
        }
        
        int res = r + c;

        res = min(res, doit(board));
        res = min(res, doit(tmp));
        
        return (res == r + c) ? -1 : res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string boardARRAY[] = {"AC",
            "DB",
            "AB"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ColorfulBoard theObject;
        eq(0, theObject.theMin(board),-1);
    }
    {
        string boardARRAY[] = {"SSS",
            "SRR",
            "SMM"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ColorfulBoard theObject;
        eq(0, theObject.theMin(board),4);
    }
    {
        string boardARRAY[] = {"BBBBBBBB",
            "BBBBBBBB",
            "BBBBBBBB",
            "BBBBBBBB",
            "BBBBBBBB"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ColorfulBoard theObject;
        eq(1, theObject.theMin(board),5);
    }
    {
        string boardARRAY[] = {"Ab",
            "bA"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ColorfulBoard theObject;
        eq(2, theObject.theMin(board),-1);
    }
    {
        string boardARRAY[] = {"iiiii",
            "iwiwi"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ColorfulBoard theObject;
        eq(3, theObject.theMin(board),4);
    }
    {
        string boardARRAY[] = {"ffffffffff",
            "xfxxoofoxo",
            "ffffffffff",
            "xfxxoofoxo",
            "ffffffffff",
            "ooxxoofoxo",
            "xfxxoofoxo",
            "xfxxoxfxxo",
            "ffxxofffxo",
            "xfxxoxfxxo"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ColorfulBoard theObject;
        eq(4, theObject.theMin(board),17);
    }
    return 0;
}
// END CUT HERE
