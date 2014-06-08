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
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

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

class SwitchingGame {
public:
    int timeToWin(vector <string> states) {
        int n = states.size(), m = states[0].length();
        int res = n;
        string now = string(m, '-');
        vector<bool> on(n, false), off(n, false);
        REP(i,n) {
            bool turnon = false, turnoff = false;
            REP(j,m) {
                if (states[i][j] == '?') continue;
                if (states[i][j] == now[j]) continue;

                if (states[i][j] == '+') {
                    bool needon = true;
                    RFOR(k,i-1,0) {
                        if (states[k][j] != '?') break;
                        if (on[k]) {
                            needon = false;
                            break;
                        }
                    }
                    if (needon) turnon = true;
                } else {
                    bool needoff = true;
                    RFOR(k,i-1,0) {
                        if (states[k][j] != '?') break;
                        if (off[k]) {
                            needoff = false;
                            break;
                        }
                    }
                    if (needoff) turnoff = true;
                }
            }

            if (turnon) ++res;
            if (turnoff) ++res;
            on[i] = turnon;
            off[i] = turnoff;

            REP(j,m) {
                if (states[i][j] != '?') now[j] = states[i][j];
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string statesARRAY[] = {"++--",
            "--++"};
        vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
        SwitchingGame theObject;
        eq(0, theObject.timeToWin(states),5);
    }
    {
        string statesARRAY[] = {"+-++",
            "+-++"};
        vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
        SwitchingGame theObject;
        eq(1, theObject.timeToWin(states),3);
    }
    {
        string statesARRAY[] = {"++",
            "+?",
            "?+",
            "++"};
        vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
        SwitchingGame theObject;
        eq(2, theObject.timeToWin(states),5);
    }
    {
        string statesARRAY[] = {"+", 
            "?",
            "?",
            "?",
            "-"};
        vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
        SwitchingGame theObject;
        eq(3, theObject.timeToWin(states),7);
    }
    {
        string statesARRAY[] = {"+??+++",
            "++??+-",
            "?++??+",
            "?-+-??",
            "??+?++",
            "++-?+?",
            "?++?-+",
            "?--+++",
            "-??-?+"}
           ;
        vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
        SwitchingGame theObject;
        eq(4, theObject.timeToWin(states),20);
    }
    return 0;
}
// END CUT HERE
