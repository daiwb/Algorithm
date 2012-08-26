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
int plist[20000],pcount=0;

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
	return n>1;
}

void initprime(){
	int i;
	for (plist[pcount++]=2,i=3;i<200000;i++)
		if (prime(i))
			plist[pcount++]=i;
}

class CompositeSmash {
public:
    string thePossible(int N, int target) {
        if ((N % target) != 0) return "No";
        if (N == target) return "Yes";

        pcount = 0;
        initprime();

        if (prime(target)) return "Yes";

        REP(i,pcount) {
            int p = plist[i];
            if (p > N) break;
            if ((N % p) == 0) {
                while ((N % p) == 0) N /= p;
                if (N > 1) return "No";
                else break;
            }
        }

        REP(i,pcount) {
            int p = plist[i];
            if (p > target) break;
            if ((target % p) == 0) {
                int c = 0;
                while ((target % p) == 0) {
                    ++c;
                    target /= p;
                }
                if (c >= 3) return "No";
                if (target > 1) return "No";
                break;
            }
        }

        return "Yes";
    }
};
// BEGIN CUT HERE
int main() {
    {
        CompositeSmash theObject;
        eq(0, theObject.thePossible(6, 2),"Yes");
    }
    {
        CompositeSmash theObject;
        eq(0, theObject.thePossible(517, 47),"Yes");
    }
    {
        CompositeSmash theObject;
        eq(1, theObject.thePossible(8, 4),"Yes");
    }
    {
        CompositeSmash theObject;
        eq(2, theObject.thePossible(12, 6),"No");
    }
    {
        CompositeSmash theObject;
        eq(3, theObject.thePossible(5, 8),"No");
    }
    {
        CompositeSmash theObject;
        eq(4, theObject.thePossible(100000, 100000),"Yes");
    }
    {
        CompositeSmash theObject;
        eq(5, theObject.thePossible(5858, 2),"Yes");
    }
    {
        CompositeSmash theObject;
        eq(6, theObject.thePossible(81461, 2809),"No");
    }
    {
        CompositeSmash theObject;
        eq(7, theObject.thePossible(65536, 256),"No");
    }
    return 0;
}
// END CUT HERE
