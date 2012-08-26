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

class EllysJuice {
public:
    vector <string> getWinners(vector <string> players) {
        if (players.size() == 1) return players;
        vector <string> res;
        map<string, int> mp;
        REP(i,players.size()) {
            if (mp.find(players[i]) == mp.end()) mp[players[i]] = 1;
            else ++mp[players[i]];
        }
        for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if ((*it).second >= 2) res.push_back((*it).first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string playersARRAY[] = { "elly", "kriss", "stancho", "elly", "stancho" };
        vector <string> players( playersARRAY, playersARRAY+ARRSIZE(playersARRAY) );
        string retrunValueARRAY[] = {"elly", "stancho" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        EllysJuice theObject;
        eq(0, theObject.getWinners(players),retrunValue);
    }
    {
        string playersARRAY[] = {"torb", "elly", "stancho", "kriss"};
        vector <string> players( playersARRAY, playersARRAY+ARRSIZE(playersARRAY) );
        EllysJuice theObject;
        eq(1, theObject.getWinners(players),vector <string>());
    }
    {
        string playersARRAY[] = {"elly", "elly", "elly", "elly", "elly"};
        vector <string> players( playersARRAY, playersARRAY+ARRSIZE(playersARRAY) );
        string retrunValueARRAY[] = {"elly" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        EllysJuice theObject;
        eq(2, theObject.getWinners(players),retrunValue);
    }
    {
        string playersARRAY[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
        vector <string> players( playersARRAY, playersARRAY+ARRSIZE(playersARRAY) );
        string retrunValueARRAY[] = {"ariadne", "elly", "stancho" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        EllysJuice theObject;
        eq(3, theObject.getWinners(players),retrunValue);
    }
    return 0;
}
// END CUT HERE
