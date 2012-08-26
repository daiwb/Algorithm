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

class JingleRingle {
public:
    int profit(vector <int> buyOffers, vector <int> sellOffers, int tax) {
        REP(i,buyOffers.size()) {
            int t = buyOffers[i] * tax / 100;
            buyOffers[i] -= t;
        }
        sort(buyOffers.begin(), buyOffers.end());
        sort(sellOffers.begin(), sellOffers.end());
        int cb = buyOffers.size(), cs = sellOffers.size();
        int res = 0;
        int ib = cb - 1, is = 0;
        while (true) {
            if (ib < 0 || is >= cs) break;
            if (buyOffers[ib] >= sellOffers[is]) {
                res += buyOffers[ib] - sellOffers[is];
                --ib, ++is;
            } else {
                break;
            }
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        int buyOffersARRAY[] = {1000, 1024};
        vector <int> buyOffers( buyOffersARRAY, buyOffersARRAY+ARRSIZE(buyOffersARRAY) );
        int sellOffersARRAY[] = {990, 1011};
        vector <int> sellOffers( sellOffersARRAY, sellOffersARRAY+ARRSIZE(sellOffersARRAY) );
        JingleRingle theObject;
        eq(0, theObject.profit(buyOffers, sellOffers, 0),34);
    }
    {
        int buyOffersARRAY[] = {1000, 1001, 1002};
        vector <int> buyOffers( buyOffersARRAY, buyOffersARRAY+ARRSIZE(buyOffersARRAY) );
        int sellOffersARRAY[] = {980, 981, 982};
        vector <int> sellOffers( sellOffersARRAY, sellOffersARRAY+ARRSIZE(sellOffersARRAY) );
        JingleRingle theObject;
        eq(1, theObject.profit(buyOffers, sellOffers, 2),2);
    }
    {
        int buyOffersARRAY[] = {100, 120, 140};
        vector <int> buyOffers( buyOffersARRAY, buyOffersARRAY+ARRSIZE(buyOffersARRAY) );
        int sellOffersARRAY[] = {150, 170, 200};
        vector <int> sellOffers( sellOffersARRAY, sellOffersARRAY+ARRSIZE(sellOffersARRAY) );
        JingleRingle theObject;
        eq(2, theObject.profit(buyOffers, sellOffers, 15),0);
    }
    {
        JingleRingle theObject;
        eq(3, theObject.profit(vector <int>(), vector <int>(), 20),0);
    }
    {
        int buyOffersARRAY[] = {1692, 3281, 862};
        vector <int> buyOffers( buyOffersARRAY, buyOffersARRAY+ARRSIZE(buyOffersARRAY) );
        int sellOffersARRAY[] = {2701, 2819, 2582, 1918, 638, 601, 1128, 2760, 1949, 3074,
             615, 2221, 1691, 3226, 1351, 1329, 556, 1060, 898, 1080,
            2494, 2379, 3148, 737, 1412, 3290, 1594, 1314, 959, 3192,
            1326, 932, 1103, 937, 1670, 2017, 1403, 1282, 2949, 2940,
            2557, 940, 2561, 1248, 2385, 541, 2382, 1309, 831};
        vector <int> sellOffers( sellOffersARRAY, sellOffersARRAY+ARRSIZE(sellOffersARRAY) );
        JingleRingle theObject;
        eq(4, theObject.profit(buyOffers, sellOffers, 4),3905);
    }
    {
        int buyOffersARRAY[] = {5016, 7212, 7613, 1590, 2942, 5155, 5898, 8113, 2001, 2348,
             671, 5167, 7524, 2467, 4294, 3628, 4480, 5872, 5230, 3732,
            4637, 6419, 1431, 6335, 1652, 3005, 2125, 2193, 2183, 5856,
            1795, 5441, 2079, 7114, 2290, 4025, 5943, 1695};
        vector <int> buyOffers( buyOffersARRAY, buyOffersARRAY+ARRSIZE(buyOffersARRAY) );
        int sellOffersARRAY[] = {2407, 5602, 1350};
        vector <int> sellOffers( sellOffersARRAY, sellOffersARRAY+ARRSIZE(sellOffersARRAY) );
        JingleRingle theObject;
        eq(5, theObject.profit(buyOffers, sellOffers, 3),13195);
    }
    return 0;
}
// END CUT HERE
