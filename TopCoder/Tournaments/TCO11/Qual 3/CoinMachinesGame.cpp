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

class machine {
public:
    int need;
    int give;
    int cost;
    machine(int n, int g) : need(n), give(g) {
        cost = need - give;
    }
    bool operator<(const machine& rhs) const {
        if (cost != rhs.cost) return cost < rhs.cost;
        return need < rhs.need;
    }
};

class CoinMachinesGame {
public:
    int maxGames(int coins, vector <int> need, vector <int> give) {
        vector<machine> mm;
        REP(i,need.size()) {
            mm.push_back(machine(need[i], give[i]));
        }
        sort(mm.begin(), mm.end());
        int res = 0;
        REP(i,mm.size()) {
            machine m = mm[i];
            int t = coins - m.need;
            if (t > 0) {
                int c = t / m.cost;
                res += c;
                coins -= c * m.cost;
            }
            while (coins >= m.need) {
                coins -= m.cost;
                ++res;
            }
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        int needARRAY[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
        vector <int> need( needARRAY, needARRAY+ARRSIZE(needARRAY) );
        int giveARRAY[] = {999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999};
        vector <int> give( giveARRAY, giveARRAY+ARRSIZE(giveARRAY) );
        CoinMachinesGame theObject;
        eq(0, theObject.maxGames(1000000000, need, give),999999001);
    }
    {
        int needARRAY[] = {5,3};
        vector <int> need( needARRAY, needARRAY+ARRSIZE(needARRAY) );
        int giveARRAY[] = {4,1};
        vector <int> give( giveARRAY, giveARRAY+ARRSIZE(giveARRAY) );
        CoinMachinesGame theObject;
        eq(0, theObject.maxGames(10, need, give),7);
    }
    {
        int needARRAY[] = {16,14,11,7};
        vector <int> need( needARRAY, needARRAY+ARRSIZE(needARRAY) );
        int giveARRAY[] = {15,12,8,3};
        vector <int> give( giveARRAY, giveARRAY+ARRSIZE(giveARRAY) );
        CoinMachinesGame theObject;
        eq(1, theObject.maxGames(1000, need, give),988);
    }
    {
        int needARRAY[] = {1000,900,800,700,600,500,400,300,200,100};
        vector <int> need( needARRAY, needARRAY+ARRSIZE(needARRAY) );
        int giveARRAY[] = {701,802,503,604,405,306,107,208,1,1};
        vector <int> give( giveARRAY, giveARRAY+ARRSIZE(giveARRAY) );
        CoinMachinesGame theObject;
        eq(2, theObject.maxGames(1000000000, need, give),10869564);
    }
    {
        int needARRAY[] = {342,234,65,76,85,734,67,345,70,234};
        vector <int> need( needARRAY, needARRAY+ARRSIZE(needARRAY) );
        int giveARRAY[] = {45,78,3,10,45,12,45,57,1,230};
        vector <int> give( giveARRAY, giveARRAY+ARRSIZE(giveARRAY) );
        CoinMachinesGame theObject;
        eq(3, theObject.maxGames(12345678, need, give),3086370);
    }
    return 0;
}
// END CUT HERE
