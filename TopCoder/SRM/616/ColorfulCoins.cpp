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

class ColorfulCoins {
public:
    bool isok(LL a, LL b, LL c) {
        return b * log(a) > log(c);
    }
    int minQueries(vector<long long> values) {
        int n = values.size();
        if (n == 1) return 1;
        vector<LL> mm;
        FOR(i,1,n-1) mm.PB(values[i] / values[i - 1]);
        sort(mm.begin(), mm.end());
        int res = 0;
        int m = n - 1;
        while (++res) {
            bool ok = true;
            REP(i,m) {
                if (!isok(mm[i], res, i + 1)) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        long long valuesARRAY[] = {1LL};
        vector<long long> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoins theObject;
        eq(0, theObject.minQueries(values),1);
    }
    {
        long long valuesARRAY[] = {1LL, 3LL};
        vector<long long> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoins theObject;
        eq(1, theObject.minQueries(values),1);
    }
    {
        long long valuesARRAY[] = {1LL, 2LL, 4LL};
        vector<long long> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoins theObject;
        eq(2, theObject.minQueries(values),2);
    }
    {
        long long valuesARRAY[] = {1LL, 2LL, 4LL, 8LL, 16LL};
        vector<long long> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoins theObject;
        eq(3, theObject.minQueries(values),3);
    }
    {
        long long valuesARRAY[] = {1LL, 2LL, 6LL, 30LL, 90LL, 270LL, 810LL, 2430LL, 7290LL, 29160LL, 87480LL, 262440LL, 787320LL, 3149280LL,
             9447840LL, 28343520LL, 56687040LL, 170061120LL, 510183360LL, 1530550080LL, 3061100160LL,
             9183300480LL, 27549901440LL, 82649704320LL, 247949112960LL, 1239745564800LL, 3719236694400LL,
             14876946777600LL, 44630840332800LL, 223154201664000LL, 669462604992000LL, 2008387814976000LL,
             6025163444928000LL, 12050326889856000LL, 24100653779712000LL, 72301961339136000LL,
             289207845356544000LL, 867623536069632000LL};
        vector<long long> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoins theObject;
        eq(4, theObject.minQueries(values),4);
    }
    return 0;
}
// END CUT HERE
