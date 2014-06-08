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
#define MAXN 5000005

int plist[1000000], pcount;
bool isP[MAXN], valid[MAXN];

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++) {
		if (!(n%plist[i])) return 0;
    }
	return n>1;
}

void initprime(){
    pcount = 0;
    memset(isP, false, sizeof(isP));
    isP[2] = 1;
	int i;
	for (plist[pcount++] = 2, i = 3; i < MAXN; ++i) {
		if (prime(i)) {
            isP[i] = true;
			plist[pcount++] = i;
        }
    }
}

class SumAndProductPuzzle {
public:
    long long getSum(int A, int B) {
        // Editorial http://apps.topcoder.com/wiki/display/tc/TCO+2014+Round+2B
        // To prove each S either has no solution, or only one solution which is (1, S - 1)
        // Say there's another solution (N, S - N), then 1 + N * (S - N) - 1 is composite.
        // And N + S - N - 1 is also composite which contradicts the assumption that N * (S - N)
        // has only one factorizations (a, b) that a * b - 1 is composite.
        initprime();
        FOR(i,A,B) valid[i] = !isP[i - 1];
        FOR(x,2,(int)sqrt(B)) {
            FOR(y,x,B/x) {
                if (!isP[x + y - 1]) valid[x * y + 1] = false;
            }
        }
        LL res = 0;
        FOR(i,max(A,3),B) if (valid[i]) res += i;
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        SumAndProductPuzzle theObject;
        eq(0, theObject.getSum(30, 33),33LL);
    }
    {
        SumAndProductPuzzle theObject;
        eq(1, theObject.getSum(8, 11),19LL);
    }
    {
        SumAndProductPuzzle theObject;
        eq(2, theObject.getSum(40, 43),0LL);
    }
    {
        SumAndProductPuzzle theObject;
        eq(3, theObject.getSum(47, 74),168LL);
    }
    {
        SumAndProductPuzzle theObject;
        eq(4, theObject.getSum(1, 2),0LL);
    }
	{
        SumAndProductPuzzle theObject;
        eq(4, theObject.getSum(1, 50000),67227724LL);
    }
    {
        SumAndProductPuzzle theObject;
        eq(4, theObject.getSum(1, 500000),5051859774LL);
    }
    return 0;
}
// END CUT HERE
