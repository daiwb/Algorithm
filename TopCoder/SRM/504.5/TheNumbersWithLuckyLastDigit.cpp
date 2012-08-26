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
int mm[10];
int dd[10];
priority_queue<pair<int, int> > que;

class TheNumbersWithLuckyLastDigit {
public:
    int find(int n) {
        memset(mm, -1, sizeof(mm));
        int cnt = 2;
        while (!que.empty()) que.pop();
        que.push(make_pair(-1, -4));
        que.push(make_pair(-1, -7));
        mm[4] = mm[7] = 1;
        dd[4] = 4, dd[7] = 7;
        while (!que.empty()) {
            pair<int, int> now = que.top();
            que.pop();
            int a = -now.second, b = -now.first;

            int list[] = {4, 7};
            REP(i,2) {
                int t = a + list[0];
                if (mm[t % 10] == -1) {
                    mm[t % 10] = b + 1;
                    dd[t % 10] = t;
                    que.push(make_pair(-(b + 1), -t));
                    ++cnt;
                    if (cnt == 10) break;
                }
            }
        }

        int q = (n % 10);
        return n >= dd[q] ? mm[q] : -1;
    }

};
// BEGIN CUT HERE
int main() {
    {
        TheNumbersWithLuckyLastDigit theObject;
        eq(0, theObject.find(99),4);
    }
    {
        TheNumbersWithLuckyLastDigit theObject;
        eq(1, theObject.find(11),2);
    }
    {
        TheNumbersWithLuckyLastDigit theObject;
        eq(2, theObject.find(13),-1);
    }
    {
        TheNumbersWithLuckyLastDigit theObject;
        eq(3, theObject.find(1234567),1);
    }
    return 0;
}
// END CUT HERE
