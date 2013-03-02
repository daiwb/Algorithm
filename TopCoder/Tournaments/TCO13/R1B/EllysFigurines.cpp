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

class EllysFigurines {
public:
    int getMoves(vector <string> board, int R, int C) {
		int mat[20][20];
		int row = board.size(), col = board[0].length();
		int tot = (1 << row);
		int res = row + col;
		REP(i,row) {
			REP(j,col) {
				if (board[i][j] == 'X') mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
		REP(st,tot) {
			int tmp[20][20];
			memcpy(tmp, mat, sizeof(mat));
			vector<int> rr;
			REP(i,row) {
				if (st & (1 << i)) rr.push_back(1);
				else rr.push_back(0);
			}
			int rc = getCnt(rr, R);

			REP(i,row) {
				if (rr[i] == 1) {
					REP(j,col) {
						tmp[i][j] = 0;
					}
				}
			}
			vector<int> cc;
			REP(j,col) {
				bool fl = false;
				REP(i,row) {
					if (tmp[i][j] == 1) {
						fl = true;
						break;
					}
				}
				if (fl) cc.push_back(1);
				else cc.push_back(0);
			}
			int cn = getCnt(cc, C);

			res = min(res, rc + cn);
		}
        return res;
    }

	int getCnt(vector<int> mm, int mx) {
		int res = 0;
		REP(i,mm.size()) {
			if (mm[i] == 0) continue;
			++res;
			REP(tp,mx) {
				if (i + tp < mm.size()) mm[i + tp] = 0;
				else break;
			}
		}
		return res;
	}
};
// BEGIN CUT HERE
int main() {
    {
        string boardARRAY[] = {".X.X.",
            "XX..X",
            ".XXX.",
            "...X.",
            ".X.XX"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EllysFigurines theObject;
        eq(0, theObject.getMoves(board, 1, 2),3);
    }
    {
        string boardARRAY[] = {".X.X.",
            "XX..X",
            ".X.X.",
            "...X.",
            ".X.XX"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EllysFigurines theObject;
        eq(1, theObject.getMoves(board, 2, 2),2);
    }
    {
        string boardARRAY[] = {"XXXXXXX"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EllysFigurines theObject;
        eq(2, theObject.getMoves(board, 2, 3),1);
    }
    {
        string boardARRAY[] = {"XXXXX",
            "X....",
            "XXX..",
            "X....",
            "XXXXX"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EllysFigurines theObject;
        eq(3, theObject.getMoves(board, 1, 1),4);
    }
    {
        string boardARRAY[] = {"XXX..XXX..XXX.",
            ".X..X....X...X",
            ".X..X....X...X",
            ".X..X....X...X",
            ".X...XXX..XXX.",
            "..............",
            "...XX...XXX...",
            "....X......X..",
            "....X....XXX..",
            "....X......X..",
            "...XXX..XXX..."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EllysFigurines theObject;
        eq(4, theObject.getMoves(board, 1, 2),7);
    }
	{
        string boardARRAY[] = {
            "XXXXXXXXXXXXXX",
            "....X.X.......",
            "XXXXXXXXXXXXXX",
            "....X.X.......",
            "XXXXXXXXXXXXXX",};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EllysFigurines theObject;
        eq(4, theObject.getMoves(board, 1, 3),4);
    }
	{
        string boardARRAY[] = {
			"XXX..XXX..XXX.X",
            ".X..X....X...XX",
            ".X..X....X...X.",
            ".X..X....X...X.",
            ".X...XXX..XXX.X",
            "...............",
            "...XX...XXX....",
            "....X......X...",
            "....X....XXX..X",
            "....X......X...",
            "...XXX..XXX...X"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EllysFigurines theObject;
        eq(4, theObject.getMoves(board, 1, 2),7);
    }
    return 0;
}
// END CUT HERE
