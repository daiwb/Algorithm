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

string i2s(int n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

int plist[10000],pcount=0;
int mm[105];

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
    memset(mm, 0, sizeof(mm));
	int i;
	for (plist[pcount++]=2,i=3;i<=100;i++)
        if (prime(i)) {
            if (i >= 10 && i <= 99) mm[i] = 1;
			plist[pcount++]=i;
        }
}

bool isok(int n) {
    string str = i2s(n);
    int len = str.length();
    REP(i,len) {
        FOR(j,i+1,len-1) {
            int a = str[i] - '0', b = str[j] - '0';
            if (a == 0 || b == 0) continue;
            if (mm[a * 10 + b] == 1 || mm[b * 10 + a] == 1) return true;
        }
    }
    return false;
}

class DigitPrime {
public:
    int countNumbers(int a, int b) {
        initprime();
        int res = 0;
        FOR(i,a,b) {
            if (isok(i)) ++res;
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        DigitPrime theObject;
        eq(0, theObject.countNumbers(11, 20),6);
    }
    {
        DigitPrime theObject;
        eq(1, theObject.countNumbers(37, 98),21);
    }
    {
        DigitPrime theObject;
        eq(2, theObject.countNumbers(9003, 9003),0);
    }
    {
        DigitPrime theObject;
        eq(3, theObject.countNumbers(11, 11111),8777);
    }
    {
        DigitPrime theObject;
        eq(4, theObject.countNumbers(97463, 100000),2436);
    }
    {
        DigitPrime theObject;
        eq(5, theObject.countNumbers(33561, 33601),40);
    }
    {
        DigitPrime theObject;
        eq(6, theObject.countNumbers(11000, 11999),1000);
    }
    return 0;
}
// END CUT HERE
