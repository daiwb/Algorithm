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

int getVal(char ch) {
	if (ch >= '2' && ch <= '9') return ch - '0';
	if (ch == 'T' || ch == 'J' || ch == 'Q' || ch == 'K') return 10;
	return 11;
}

int cnt[15];
double res;

void dfs(int now, int total, double fact, int step) {
	FOR(i,2,11) {
		if (cnt[i] == 0) continue;

		double p = cnt[i] * 1.0 / total;

		if (now + i >= 21) res += fact * p * step;
		else {
			--cnt[i];
			dfs(now + i, total - 1, fact * p, step + 1);
			++cnt[i];
		}
	}
}

class TheBlackJackDivOne {
public:
    double expected(vector <string> cards) {
		FOR(i,2,11) cnt[i] = 4;
		cnt[10] = 16;
		int now = 0;
		REP(i,cards.size()) {
			int v = getVal(cards[i][0]);
			now += v;
			--cnt[v];
		}
		if (now >= 21) return 0.0;
		res = 0;
		dfs(now, 52 - cards.size(), 1.0, 1);
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string cardsARRAY[] = {"JS"};
        vector <string> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        TheBlackJackDivOne theObject;
        eq(0, theObject.expected(cards),2.105854341736695);
    }
    {
        string cardsARRAY[] = {"KD", "8S"};
        vector <string> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        TheBlackJackDivOne theObject;
        eq(1, theObject.expected(cards),1.08);
    }
    {
        string cardsARRAY[] = {"KD", "2S", "2C", "2D", "2H"};
        vector <string> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        TheBlackJackDivOne theObject;
        eq(2, theObject.expected(cards),1.0);
    }
    {
        string cardsARRAY[] = {"AS", "KS", "9S", "JC", "2D"};
        vector <string> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        TheBlackJackDivOne theObject;
        eq(3, theObject.expected(cards),0.0);
    }
    return 0;
}
// END CUT HERE
