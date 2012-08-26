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

class Cut {
public:
    int getMaximum(vector <int> mm, int maxCuts) {
        int res = 0;
        REP(i,mm.size()) {
            if (mm[i] == 10) {
                ++res;
                mm[i] = 0;
            }
        }
        while (maxCuts > 0) {
            --maxCuts;
            sort(mm.begin(), mm.end());
            bool fl = false;
            REP(i,mm.size()) {
                if (mm[i] == 20) {
                    res += 2;
                    mm[i] = 0;
                    fl = true;
                    break;
                }
            }
            if (fl) continue;
            REP(i,mm.size()) {
                if (mm[i] == 0) continue;
                if ((mm[i] % 10) == 0) {
                    mm[i] -= 10;
                    ++res;
                    fl = true;
                    break;
                }
            }
            if (fl) continue;
            REP(i,mm.size()) {
                if (mm[i] > 10) {
                    mm[i] -= 10;
                    ++res;
                    fl = true;
                    break;
                }
            }
            if (!fl) break;
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int eelLengthsARRAY[] = {13, 20, 13};
        vector <int> eelLengths( eelLengthsARRAY, eelLengthsARRAY+ARRSIZE(eelLengthsARRAY) );
        Cut theObject;
        eq(0, theObject.getMaximum(eelLengths, 2),3);
    }
    {
        int eelLengthsARRAY[] = {5, 5, 5, 5};
        vector <int> eelLengths( eelLengthsARRAY, eelLengthsARRAY+ARRSIZE(eelLengthsARRAY) );
        Cut theObject;
        eq(1, theObject.getMaximum(eelLengths, 2),0);
    }
    {
        int eelLengthsARRAY[] = {34, 10, 48};
        vector <int> eelLengths( eelLengthsARRAY, eelLengthsARRAY+ARRSIZE(eelLengthsARRAY) );
        Cut theObject;
        eq(2, theObject.getMaximum(eelLengths, 4),5);
    }
    {
        int eelLengthsARRAY[] = {30, 50, 30, 50};
        vector <int> eelLengths( eelLengthsARRAY, eelLengthsARRAY+ARRSIZE(eelLengthsARRAY) );
        Cut theObject;
        eq(3, theObject.getMaximum(eelLengths, 350),16);
    }
    return 0;
}
// END CUT HERE
