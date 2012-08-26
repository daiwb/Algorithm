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
#define MAXN 55
int match1[55], match2[55];

#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

int plist[10000],pcount=0;
int vv[3000];

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
    pcount = 0;
    memset(vv, 0, sizeof(vv));
    vv[2] = 1;
	int i;
	for (plist[pcount++]=2,i=3;i<3000;i++)
        if (prime(i)) {
            plist[pcount++]=i;
            vv[i] = 1;
        }
}

int mm[55][55];
int tt[55][55];

class PrimePairs {
public:
    vector <int> matches(vector <int> numbers) {
        vector <int> res;
        initprime();
        memset(mm, 0, sizeof(mm));
        vector<int> v1, v2;
        int n = numbers.size();
        REP(i,n) {
            if (numbers[i] & 1) v1.push_back(numbers[i]);
            else v2.push_back(numbers[i]);
        }
        if (v1.size() != v2.size()) return res;
        if (!(numbers[0] & 1)) swap(v1, v2);
        int sz = v1.size();
        REP(i,sz) {
            REP(j,sz) {
                if (vv[v1[i] + v2[j]] == 1) mm[i][j] = 1;
            }
        }
        
        
        REP(i,sz) {
            if (mm[0][i] == 0) continue;
            memcpy(tt, mm, sizeof(mm));
            REP(j,sz) {
                tt[0][j] = 0;
                tt[j][i] = 0;
            }
            tt[0][i] = 1;

            int cnt = hungary(sz, sz, tt, match1, match2);
            if (cnt * 2 == n) res.push_back(v2[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        int numbersARRAY[] = { 1, 4, 7, 10, 11, 12 };
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {4, 10 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PrimePairs theObject;
        eq(0, theObject.matches(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = { 11, 1, 4, 7, 10, 12 };
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {12 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PrimePairs theObject;
        eq(1, theObject.matches(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = { 8, 9, 1, 14 };
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        PrimePairs theObject;
        eq(2, theObject.matches(numbers),vector <int>());
    }
    {
        int numbersARRAY[] = { 34, 39, 32, 4, 9, 35, 14, 17 };
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {9, 39 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PrimePairs theObject;
        eq(3, theObject.matches(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = { 941, 902, 873, 841, 948, 851, 945, 854, 815, 898,
             806, 826, 976, 878, 861, 919, 926, 901, 875, 864 }
           ;
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {806, 926 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PrimePairs theObject;
        eq(4, theObject.matches(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = {347, 149, 331, 120, 96, 804, 294, 918, 35, 191, 925, 234, 739, 197,
            715, 777, 931, 894, 982, 969, 637, 349, 732, 424, 751, 556, 752, 369, 546, 211, 952,
            405, 815, 862, 443, 230, 356, 238, 148, 694, 11, 967, 161, 467, 524, 65, 904, 377, 605, 444};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        PrimePairs theObject;
        eq(5, theObject.matches(numbers),vector <int>());
    }
    return 0;
}
// END CUT HERE
