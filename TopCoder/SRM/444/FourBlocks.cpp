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

int mm[25][1<<10];
int row, col;
vector <string> grid;

int dp(int level, int state) {
    int& res = mm[level][state];
    if (res != -1) return res;

    int total = (1 << col);

    int v[10];
    REP(i,col) {
        if (state & (1 << i)) v[i] = 1;
        else v[i] = 0;
    }

    REP(i,col) {
        if (v[i] == 1 && grid[level][col] == '1') return res = 0;
    }

    res = 0;
    REP(s,total) {
        int d[10];
        REP(i,col) {
            if (s & (1 << i)) d[i] = 1;
            else d[i] = 0;
        }
        
        bool flag = true;
        REP(i,col) {
            if (v[i] == 1 && d[i] == 0) {
                flag = false;
                break;
            }
        }
        
        if (!flag) continue;
        REP(i,col) {
            if (d[i] == 1 && grid[level][i] == '1') {
                flag = false;
                break;
            }
        }
        
        if (!flag) continue;
        REP(i,col) {
            if (d[i] == 1) {
                if (i + 1 >= col || d[i + 1] != 1 || v[i] != v[i + 1]) {
                    flag = false;
                    break;
                }
                ++i;
            }
        }
        if (!flag) continue;
        
        int val = 0;
        REP(i,col) {
            if (d[i] == 1) val += 4;
            else val += 1;
        }
        
        int ns = 0;
        REP(i,col) {
            if (d[i] == 1 && v[i] == 0) {
                ns |= (1 << i);
            }
        }
        
        if (level == row - 1) {
            bool fl = true;
            REP(i,col) {
                if (ns & (1 << i)) {
                    fl = false;
                    break;
                }
            }
            if (fl) res = max(res, val);
        } else {
            int next = dp(level + 1, ns);
            if (next != 0) res = max(res, next + val);
        }
    }
    return res;
}

class FourBlocks {
public:
    int maxScore(vector <string> _grid) {
        grid.clear();
        REP(i,_grid[0].length()) {
            string str = "";
            REP(j,_grid.size()) str += _grid[j][i];
            grid.push_back(str);
        }
        row = grid.size(), col = grid[0].length();
        memset(mm, -1, sizeof(mm));
        int res = dp(0, 0);
        return res;
    }
};

// BEGIN CUT HERE
int main() {
    {
        string gridARRAY[] = {"............1.", "..............", "..1.....1.....", ".......1.....1", "1.............", "...1.....1....", "...1.....1.1..", "..............", "..........1...", "1...1...1....."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FourBlocks theObject;
        eq(3, theObject.maxScore(grid),440);
    }
    {
        string gridARRAY[] = {".....1..1..",
                              "..1.....1.."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FourBlocks theObject;
        eq(0, theObject.maxScore(grid),70);
    }
    {
        string gridARRAY[] = {"...1.",
                              ".....",
                              ".1..1",
                              ".....",
                              "1...."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FourBlocks theObject;
        eq(1, theObject.maxScore(grid),73);
    }
    {
        string gridARRAY[] = {"...1.",
                              ".1...",
                              "..1.1",
                              "1...."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FourBlocks theObject;
        eq(2, theObject.maxScore(grid),20);
    }
    {
        string gridARRAY[] = {".....1...",
                              ".....1...",
                              "111111111",
                              ".....1...",
                              ".....1..."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FourBlocks theObject;
        eq(3, theObject.maxScore(grid),117);
    }
    return 0;
}
// END CUT HERE
