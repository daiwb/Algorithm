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

class FoxAndKgram {
public:
    vector<int> len;
    int num[55];
    int n;
    bool isok(int k) {
        int t[55];
        memcpy(t, num, sizeof(num));
        int cnt = t[k];
        int tar = k / 2;
        FOR(a,1,tar) {
            int b = k - 1 - a;
            int ad = (a == b) ? t[a] / 2 : min(t[a], t[b]);
            cnt += ad;
            t[a] -= ad;
            t[b] -= ad;
        }
        return cnt >= k;
    }
    int maxK(vector <int> _len) {
        len = _len;
        n = len.size();
        memset(num, 0, sizeof(num));
        REP(i,n) ++num[len[i]];
        RFOR(i,n,1) {
            if (isok(i)) return i;
        }
        return 0;
    }

};
// BEGIN CUT HERE
int main() {
    {
        int lenARRAY[] = {1,1,1,1,3};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        FoxAndKgram theObject;
        eq(0, theObject.maxK(len),3);
    }
    {
        int lenARRAY[] = {2,2,1,3,5,5,5};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        FoxAndKgram theObject;
        eq(1, theObject.maxK(len),5);
    }
    {
        int lenARRAY[] = {1};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        FoxAndKgram theObject;
        eq(2, theObject.maxK(len),1);
    }
    {
        int lenARRAY[] = {2,2,2,2,2,2,2,2,2,2};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        FoxAndKgram theObject;
        eq(3, theObject.maxK(len),5);
    }
    {
        int lenARRAY[] = {1,2,3,1,2,4,2,3,1};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        FoxAndKgram theObject;
        eq(4, theObject.maxK(len),4);
    }
    {
        int lenARRAY[] = {2,3,5,7,11,13,17,19,23,29};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        FoxAndKgram theObject;
        eq(5, theObject.maxK(len),0);
    }
    return 0;
}
// END CUT HERE
