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
class PasswordXGuessing {
public:
    long long howMany(vector <string> g) {
        LL ret = 0;
        int n = g.size(), len = g[0].length();
        REP(lt,len) {
            FOR(ch,'0','9') {
                if (g[0][lt] == ch) continue;
                string tmp = g[0];
                tmp[lt] = ch;
                bool isok = true;
                REP(i,n) {
                    int d = 0;
                    REP(j,len) if (tmp[j] != g[i][j]) ++d;
                    if (d != 1) {
                        isok = false;
                        break;
                    }
                }
                if (isok) ++ret;
            }
        }
        return ret;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string guessesARRAY[] = {"58", "47"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        PasswordXGuessing theObject;
        eq(0, theObject.howMany(guesses),2LL);
    }
    {
        string guessesARRAY[] = {"539", "540", "541"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        PasswordXGuessing theObject;
        eq(1, theObject.howMany(guesses),1LL);
    }
    {
        string guessesARRAY[] = {"12", "34", "56", "78"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        PasswordXGuessing theObject;
        eq(2, theObject.howMany(guesses),0LL);
    }
    {
        string guessesARRAY[] = {"2", "3", "5"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        PasswordXGuessing theObject;
        eq(3, theObject.howMany(guesses),7LL);
    }
    {
        string guessesARRAY[] = {"4747", "4747", "4747", "4747"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        PasswordXGuessing theObject;
        eq(4, theObject.howMany(guesses),36LL);
    }
    return 0;
}
// END CUT HERE
