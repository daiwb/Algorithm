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
#define MAXN 17

int mm[1 << MAXN][MAXN + 5];
int memo[1 << MAXN];
int n;

class RabbitStepping {
public:
    double getExpected(string field, int r) {
		n = field.length();

		if (n == 2) {
			return r;
		}

		memset(mm, -1, sizeof(mm));
		memset(memo, 0, sizeof(memo));

		int total = (1 << n);
		int ct = 0;

		REP(s,total) {
			int cnt = 0;
			REP(i,n) {
				if (s & (1 << i)) ++cnt;
			}
			if (cnt != r) continue;

			memo[s] = 1;
			++ct;
		}

		FOR(rr,2,n) {
			REP(s,total) {
				if (rr == 2) {
					mm[s][2] = 0;
					REP(i,2) {
						if (s & (1 << i)) mm[s][2] += 1;
					}
				} else {
					int dd[MAXN + 5];
					memset(dd, 0, sizeof(dd));

					REP(i,rr) {
						if (!(s & (1 << i))) continue;

						if (i == 0) dd[1] += 1;
						else if (i == rr - 1 || i == rr - 2) dd[i - 1] += 1;
						else {
							if (field[i] == 'W') dd[i - 1] += 1;
							else if (field[i] == 'B') dd[i + 1] += 1;
							else {
								if (rr == n) {
									dd[i - 1] += 1;
								} else {
									if (rr % 2) dd[i + 1] += 1;
									else dd[i - 1] += 1;
								}
							}
						}
					}

					int next = 0;
					REP(i,rr - 1) {
						if (dd[i] == 1) next |= (1 << i);
					}

					mm[s][rr] = mm[next][rr - 1];
				}
			}
		}

		int sum = 0;
		REP(s,total) {
			if (memo[s] == 0) continue;
			sum += mm[s][n];
		}

        double res = sum * 1.0 / ct;
        return res;
    }
};
// BEGIN CUT HERE
int main() {
	{
        RabbitStepping theObject;
        eq(3, theObject.getExpected("RRBBRBWWBRRRBWBRB", 10),1.00287947347);
    }
    {
        RabbitStepping theObject;
        eq(0, theObject.getExpected("WRBRW", 4),0.8);
    }
    {
        RabbitStepping theObject;
        eq(1, theObject.getExpected("WWB", 2),1.3333333333333333);
    }
    {
        RabbitStepping theObject;
        eq(2, theObject.getExpected("WW", 1),1.0);
    }
    {
        RabbitStepping theObject;
        eq(3, theObject.getExpected("BBBBBBBBBB", 4),0.9523809523809523);
    }
    {
        RabbitStepping theObject;
        eq(4, theObject.getExpected("RRBRRWRRBRRW", 8),0.9696969696969697);
    }
    return 0;
}
// END CUT HERE
