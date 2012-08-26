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

class RepaintTheChessboard {
public:
    int getSteps(vector<string>& board, int x, int y, int flag) {
        int ret = 0;
        REP(i,8) {
            REP(j,8) {
                if ((i + j & 1) == flag) {
                    if (board[i + x][j + y] == 'B') ++ret;
                } else {
                    if (board[i + x][j + y] == 'W') ++ret;
                }
            }
        }
        return ret;
    }
    int minimumChanges(vector<string> board) {
        int res = 1000000000;
        int m = board.size(), n = board[0].length();
        FOR(i,0,m-8) {
            FOR(j,0,n-8) {
                res = min(res, getSteps(board, i, j, 1));
                res = min(res, getSteps(board, i, j, 0));
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string boardARRAY[] = {"BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RepaintTheChessboard theObject;
        eq(0, theObject.minimumChanges(board),0);
    }
    {
        string boardARRAY[] = {"WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBBBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RepaintTheChessboard theObject;
        eq(1, theObject.minimumChanges(board),1);
    }
    {
        string boardARRAY[] = {"BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBB",
            "BBBBBBBBBBBBBBBBBBBBBBW"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RepaintTheChessboard theObject;
        eq(2, theObject.minimumChanges(board),31);
    }
    {
        string boardARRAY[] = {"BBBBBBBBBB",
            "BBWBWBWBWB",
            "BWBWBWBWBB",
            "BBWBWBWBWB",
            "BWBWBWBWBB",
            "BBWBWBWBWB",
            "BWBWBWBWBB",
            "BBWBWBWBWB",
            "BWBWBWBWBB",
            "BBBBBBBBBB"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RepaintTheChessboard theObject;
        eq(3, theObject.minimumChanges(board),0);
    }
    {
        string boardARRAY[] = {"WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBBBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWWWB",
            "BWBWBWBW"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RepaintTheChessboard theObject;
        eq(4, theObject.minimumChanges(board),2);
    }
    {
        string boardARRAY[] = {"BWWBWWBWWBWW",
            "BWWBWBBWWBWW",
            "WBWWBWBBWWBW",
            "BWWBWBBWWBWW",
            "WBWWBWBBWWBW",
            "BWWBWBBWWBWW",
            "WBWWBWBBWWBW",
            "BWWBWBWWWBWW",
            "WBWWBWBBWWBW",
            "BWWBWBBWWBWW",
            "WBWWBWBBWWBW"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RepaintTheChessboard theObject;
        eq(5, theObject.minimumChanges(board),15);
    }
    return 0;
}
// END CUT HERE
