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

int mm[2500];
double vv[2500];

class TheSwapsDivOne {
public:
    double find(vector <string> sequence, int k) {
        string str = "";
        REP(i,sequence.size()) str += sequence[i];
        int n = str.length();
        REP(i,n) mm[i] = str[i] - '0';

        double pn = (n - 2) * 1.0 / n, pc = 1 - pn;
        double p1 = 1.0, p2 = 1 - p1;
        FOR(i,1,k) {
            p1 = p1 * pn + p2 * pc / (n - 1);
            p2 = 1 - p1;
        }

        double sum = 0;
        REP(i,n) {
            vv[i] = (i + 1) * (n - i);
            sum += vv[i];
        }

        double total = 0.0;
        REP(i,n) total += mm[i] * ((sum - vv[i]) * p2 / (n - 1) + vv[i] * p1);
        return total / (n * (n - 1) / 2 + n);
    }
};
// BEGIN CUT HERE
int main() {
    {
        string sequenceARRAY[] = {"4", "77"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(0, theObject.find(sequence, 1),10.0);
    }
    {
        string sequenceARRAY[] = {"4", "77"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(1, theObject.find(sequence, 47),10.0);
    }
    {
        string sequenceARRAY[] = {"1", "1", "1", "1", "1", "1", "1"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(2, theObject.find(sequence, 1000000),3.0);
    }
    {
        string sequenceARRAY[] = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(3, theObject.find(sequence, 7),98.3238536775161);
    }
    return 0;
}
// END CUT HERE
