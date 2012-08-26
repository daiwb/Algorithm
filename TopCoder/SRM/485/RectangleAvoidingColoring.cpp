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
#define PB push_back
#define MP make_pair
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

int h, w;
LL res;
vector<string> board, mm;
LL memo[55][2][2];

class RectangleAvoidingColoring {
public:
    long long count(vector <string> _board) {
        board = _board;
        h = board.size(), w = board[0].size();
        if (h < w) {
            vector<string> g(w, string(h, '?'));
            REP(i,w) REP(j,h) g[i][j] = board[j][i];
            board = g;
            swap(h, w);
        }
        
        if (w == 1) {
            int cnt = 0;
            REP(i,h) if (board[i][0] == '?') ++cnt;
            return 1LL << cnt;
        }

        if (w == 2) {
            memset(memo, -1, sizeof(memo));
            return dp(0, 0, 0);
        }
        
        // http://forums.topcoder.com/?module=Thread&threadID=690923&start=0
        if (h >= 7 || (w >= 5 && h >= 5)) return 0;
        
        res = 0;
        mm = board;
        go(0, 0);
        return res;
    }

    LL dp(int now, int w, int b) {
        LL& ret = memo[now][w][b];
        if (ret != -1) return ret;
        
        if (now == h) return ret = 1;
        
        ret = 0;

        if (board[now][0] != 'B' && board[now][1] != 'B') {
            if (w == 0) ret += dp(now + 1, 1, b);
        }
        if (board[now][0] != 'W' && board[now][1] != 'W') {
            if (b == 0) ret += dp(now + 1, w, 1);
        }
        if (board[now][0] == '?' && board[now][1] == '?') {
            ret += dp(now + 1, w, b) << 1;
        }
        if (board[now][0] != board[now][1]) {
            ret += dp(now + 1, w, b);
        }

        return ret;
    }

    void go(int r, int c) {
        if (r == h) {
            ++res;
            return;
        }

        bool ww = isok(r, c, 'W'), bb = isok(r, c, 'B');
        int nr = r, nc = c + 1;
        if (nc == w) ++nr, nc = 0;
        if (board[r][c] != 'B') {
            if (ww) {
                mm[r][c] = 'W';
                go(nr, nc);
            }
        }
        if (board[r][c] != 'W') {
            if (bb) {
                mm[r][c] = 'B';
                go(nr, nc);
            }
        }
    }

    bool isok(int r, int c, char color) {
        REP(i,r) {
            REP(j,c) {
                if (mm[i][j] == color &&
                    mm[i][c] == color &&
                    mm[r][j] == color) return false;
            }
        }
        return true;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string boardARRAY[] = {"??",
            "??"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RectangleAvoidingColoring theObject;
        eq(0, theObject.count(board),14LL);
    }
    {
        string boardARRAY[] = {"B?",
            "?B"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RectangleAvoidingColoring theObject;
        eq(1, theObject.count(board),3LL);
    }
    {
        string boardARRAY[] = {"WW",
            "WW"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RectangleAvoidingColoring theObject;
        eq(2, theObject.count(board),0LL);
    }
    {
        string boardARRAY[] = {"??B??",
            "W???W",
            "??B??"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RectangleAvoidingColoring theObject;
        eq(3, theObject.count(board),12LL);
    }
    {
        string boardARRAY[] = {"??",
            "W?",
            "W?",
            "?W",
            "W?"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RectangleAvoidingColoring theObject;
        eq(4, theObject.count(board),16LL);
    }
    return 0;
}
// END CUT HERE
