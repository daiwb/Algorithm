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

#define INF 1000000000

int vv[55];
int n, m, num;
vector<int> books;

int mm1[55][55], mm2[55][55], dd[55][55];

int dp(int idx, int st) {
    int& res = dd[idx][st];
    if (res != INF) return res;

    if (idx == num) return res = mm1[idx][st] = mm2[idx][st] = 0;

    res = -INF;

    FOR(i,st,n-1) {
        int tmp = dp(idx + 1, i + 1);
        if (tmp == -INF) continue;

        tmp += ((vv[idx] == 1) ? -books[i] : books[i]);
        
        if (res == -INF || tmp >= res) {
            res = tmp;
            mm1[idx][st] = mm1[idx + 1][i + 1] + ((vv[idx] == 1) ? books[i] : 0);
            mm2[idx][st] = mm2[idx + 1][i + 1] + ((vv[idx] == 1) ? 0 : books[i]);
        }
    }

    return res;
}

class HeavyBooks {
public:
    vector <int> findWeight(vector <int> _books, vector <int> moves) {
        books = _books;
        sort(books.begin(), books.end());
        n = books.size();
        m = moves.size();
        num = moves[0];
        vector<int> tt, ww;
        REP(i,num) ww.push_back(i);
        FOR(i,1,m-1) {
            int x = moves[i];
            if (i & 1) {
                REP(q,x) {
                    if (ww.empty()) break;
                    tt.push_back(ww.back());
                    ww.pop_back();
                }
            } else {
                REP(q,x) {
                    if (tt.empty()) break;
                    ww.push_back(tt.back());
                    tt.pop_back();
                }
            }
            sort(tt.begin(), tt.end());
            sort(ww.begin(), ww.end());
        }
        REP(i,tt.size()) vv[tt[i]] = 1;
        REP(i,ww.size()) vv[ww[i]] = 0;

        REP(i,55) REP(j,55) dd[i][j] = INF;
        dp(0, 0);

        vector <int> res;
        res.push_back(mm1[0][0]);
        res.push_back(mm2[0][0]);
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int booksARRAY[] = {566, 499, 6302, 4522, 19049, 7073, 18191, 4371, 16230, 10693, 15822, 7528};
        vector <int> books( booksARRAY, booksARRAY+ARRSIZE(booksARRAY) );
        int movesARRAY[] = {6, 4, 2, 6, 6, 7, 5, 3};
        vector <int> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
        int retrunValueARRAY[] = {21402, 8893 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HeavyBooks theObject;
        eq(0, theObject.findWeight(books, moves),retrunValue);
    }
    {
        int booksARRAY[] = {5,2,3,1};
        vector <int> books( booksARRAY, booksARRAY+ARRSIZE(booksARRAY) );
        int movesARRAY[] = {3,2,1,1,1};
        vector <int> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
        int retrunValueARRAY[] = {3, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HeavyBooks theObject;
        eq(0, theObject.findWeight(books, moves),retrunValue);
    }
    {
        int booksARRAY[] = {10, 100, 1000};
        vector <int> books( booksARRAY, booksARRAY+ARRSIZE(booksARRAY) );
        int movesARRAY[] = {2, 3};
        vector <int> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
        int retrunValueARRAY[] = {110, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HeavyBooks theObject;
        eq(1, theObject.findWeight(books, moves),retrunValue);
    }
    {
        int booksARRAY[] = {155870,565381};
        vector <int> books( booksARRAY, booksARRAY+ARRSIZE(booksARRAY) );
        int movesARRAY[] = {1,1,1};
        vector <int> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
        int retrunValueARRAY[] = {0, 565381 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HeavyBooks theObject;
        eq(2, theObject.findWeight(books, moves),retrunValue);
    }
    {
        int booksARRAY[] = {500,500,500,500};
        vector <int> books( booksARRAY, booksARRAY+ARRSIZE(booksARRAY) );
        int movesARRAY[] = {4,1,1,3,2};
        vector <int> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
        int retrunValueARRAY[] = {500, 1500 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HeavyBooks theObject;
        eq(3, theObject.findWeight(books, moves),retrunValue);
    }
    {
        int booksARRAY[] = {1,1,1,1,1000000};
        vector <int> books( booksARRAY, booksARRAY+ARRSIZE(booksARRAY) );
        int movesARRAY[] = {1};
        vector <int> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
        int retrunValueARRAY[] = {0, 1000000 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HeavyBooks theObject;
        eq(4, theObject.findWeight(books, moves),retrunValue);
    }
    {
        int booksARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        vector <int> books( booksARRAY, booksARRAY+ARRSIZE(booksARRAY) );
        int movesARRAY[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
        vector <int> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
        int retrunValueARRAY[] = {110, 100 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HeavyBooks theObject;
        eq(5, theObject.findWeight(books, moves),retrunValue);
    }
    return 0;
}
// END CUT HERE
