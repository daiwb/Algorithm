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

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

inline int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

class WakingUp {
public:
    int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
        int n = period.size();
        int c = 1;
        REP(i,n) c = lcm(c, period[i]);
        vector<pair<int, int> > mm;
        REP(i,n) mm.push_back(make_pair(start[i], i));
        int last = 0;
        LL mi = 0, cur = 0;
        while (true) {
            sort(mm.begin(), mm.end());
            int t = mm[0].first;
            if (t > c) {
                cur += D * (c - last);
                break;
            }
            int add = D * (t - last);
            last = t;
            int del = 0;
            REP(i,n) {
                if (mm[i].first != t) break;
                int idx = mm[i].second;
                del += volume[idx];
                mm[i].first += period[idx];
            }
            cur += add - del;
            mi = min(mi, cur);
        }
        if (cur < 0) return -1;
        return -mi;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int periodARRAY[] = {2, 3};
        vector <int> period( periodARRAY, periodARRAY+ARRSIZE(periodARRAY) );
        int startARRAY[] = {1, 2};
        vector <int> start( startARRAY, startARRAY+ARRSIZE(startARRAY) );
        int volumeARRAY[] = {3, 4};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUp theObject;
        eq(0, theObject.maxSleepiness(period, start, volume, 3),2);
    }
    {
        int periodARRAY[] = {1};
        vector <int> period( periodARRAY, periodARRAY+ARRSIZE(periodARRAY) );
        int startARRAY[] = {1};
        vector <int> start( startARRAY, startARRAY+ARRSIZE(startARRAY) );
        int volumeARRAY[] = {17};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUp theObject;
        eq(1, theObject.maxSleepiness(period, start, volume, 17),0);
    }
    {
        int periodARRAY[] = {1};
        vector <int> period( periodARRAY, periodARRAY+ARRSIZE(periodARRAY) );
        int startARRAY[] = {1};
        vector <int> start( startARRAY, startARRAY+ARRSIZE(startARRAY) );
        int volumeARRAY[] = {23};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUp theObject;
        eq(2, theObject.maxSleepiness(period, start, volume, 17),-1);
    }
    {
        int periodARRAY[] = {9, 2, 5, 5, 7};
        vector <int> period( periodARRAY, periodARRAY+ARRSIZE(periodARRAY) );
        int startARRAY[] = {6, 1, 4, 1, 6};
        vector <int> start( startARRAY, startARRAY+ARRSIZE(startARRAY) );
        int volumeARRAY[] = {71, 66, 7, 34, 6};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUp theObject;
        eq(3, theObject.maxSleepiness(period, start, volume, 50),78);
    }
    {
        int periodARRAY[] = {5, 6, 5, 3, 8, 3, 4};
        vector <int> period( periodARRAY, periodARRAY+ARRSIZE(periodARRAY) );
        int startARRAY[] = {1, 1, 3, 2, 6, 3, 3};
        vector <int> start( startARRAY, startARRAY+ARRSIZE(startARRAY) );
        int volumeARRAY[] = {42, 85, 10, 86, 21, 78, 38};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUp theObject;
        eq(4, theObject.maxSleepiness(period, start, volume, 88),-1);
    }
    return 0;
}
// END CUT HERE
