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

vector<int> heights;

bool isok(int i1, int i2, int i3) {
    LL h1 = heights[i1], h2 = heights[i2], h3 = heights[i3];
    LL left = (h3 - h1) * (i2 - i1);
    LL right = (h2 - h1) * (i3 - i1);
    if (left > right) return true;
    else return false;
}

class BestView {
public:
    int numberOfBuildings(vector<int> _heights) {
        heights = _heights;
        int res = 0;
        int n = heights.size();
        REP(i,n) {
            int cnt = 0;
            FOR(j,0,i-1) {
                bool ok = true;
                FOR(k,j+1,i-1) {
                    if (!isok(j, k, i)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ++cnt;
            }
            FOR(j,i+1,n-1) {
                bool ok = true;
                FOR(k,i+1,j-1) {
                    if (!isok(i, k, j)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        int heightsARRAY[] = {10};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BestView theObject;
        eq(0, theObject.numberOfBuildings(heights),0);
    }
    {
        int heightsARRAY[] = {5,5,5,5};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BestView theObject;
        eq(1, theObject.numberOfBuildings(heights),2);
    }
    {
        int heightsARRAY[] = {1,2,7,3,2};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BestView theObject;
        eq(2, theObject.numberOfBuildings(heights),4);
    }
    {
        int heightsARRAY[] = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BestView theObject;
        eq(3, theObject.numberOfBuildings(heights),7);
    }
    {
        int heightsARRAY[] = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BestView theObject;
        eq(4, theObject.numberOfBuildings(heights),6);
    }
    {
        int heightsARRAY[] = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BestView theObject;
        eq(5, theObject.numberOfBuildings(heights),7);
    }
    return 0;
}
// END CUT HERE
