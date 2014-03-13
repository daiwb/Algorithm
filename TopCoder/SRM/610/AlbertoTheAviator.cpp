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

class AlbertoTheAviator {
public:
    int MaximumFlights(int F, vector <int> duration, vector <int> refuel) {
        int n = duration.size();
        vector<pair<int, int>> vf;
        REP(i,n) vf.push_back(make_pair(refuel[i], duration[i]));
        sort(vf.begin(), vf.end());
        vector<int> mm(F + 1);
        RFOR(i,n-1,0) {
            int df = vf[i].second - vf[i].first;
            FOR(j,vf[i].second, F) mm[j - df] = max(mm[j - df], mm[j] + 1);
        }
        int res = 0;
        FOR(i,0,F) res = max(res, mm[i]);
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int durationARRAY[] = {10};
        vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
        int refuelARRAY[] = {0};
        vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
        AlbertoTheAviator theObject;
        eq(0, theObject.MaximumFlights(10, duration, refuel),1);
    }
    {
        int durationARRAY[] = {8, 4};
        vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
        int refuelARRAY[] = {0, 2};
        vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
        AlbertoTheAviator theObject;
        eq(1, theObject.MaximumFlights(10, duration, refuel),2);
    }
    {
        int durationARRAY[] = {4, 8, 2, 1};
        vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
        int refuelARRAY[] = {2, 0, 0, 0};
        vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
        AlbertoTheAviator theObject;
        eq(2, theObject.MaximumFlights(12, duration, refuel),3);
    }
    {
        int durationARRAY[] = {4, 6};
        vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
        int refuelARRAY[] = {0, 1};
        vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
        AlbertoTheAviator theObject;
        eq(3, theObject.MaximumFlights(9, duration, refuel),2);
    }
    {
        int durationARRAY[] = {101};
        vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
        int refuelARRAY[] = {100};
        vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
        AlbertoTheAviator theObject;
        eq(4, theObject.MaximumFlights(100, duration, refuel),0);
    }
    {
        int durationARRAY[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365};
        vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
        int refuelARRAY[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364};
        vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
        AlbertoTheAviator theObject;
        eq(5, theObject.MaximumFlights(1947, duration, refuel),3);
    }
    return 0;
}
// END CUT HERE
