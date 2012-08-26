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

double mm[105][105][105];
int flag[105][105][105];
int N, M, K;
double total;
int m1, m2;

double dp(int left, int i1, int i2) {
    int& fl = flag[left][i1][i2];
    double& ret = mm[left][i1][i2];

    if (fl != 0) return ret;

    /*if (i1 == i2 + 1) {
        fl = 1;
        int c1 = i2, c2 = left - c1;
        ret = 1.0;
        FOR(i,1,left) ret *= i;
        FOR(i,1,c1) ret /= i;
        FOR(i,1,c2) ret /= i;
        REP(i,c1) ret *= m1 / total;
        REP(i,c2) ret *= m2 / total;
        return ret;
    }*/

    if (left > 0 && i1 == 1 && i2 == left) {
        fl = 1;
        ret = 1.0;
        REP(i,left) ret /= total;
        return ret;
    }

    if (i2 > left) {
        fl = 1;
        ret = 0;
        return ret;
    }

    if (left == 0) {
        fl = 1;
        if (i1 == i2 + 1) ret = 1.0;
        else ret = 0.0;
        return ret;
    }

    ret = 0;

    if (i1 > 1) {
        ret += m1 * dp(left - 1, i1 - 1, i2 - 1) / total;
    }

    if (left > i2) {
        ret += m2 * dp(left - 1, i1, i2) / total;
    }

    if (i2 >= i1) {
        ret += dp(left - 1, i1, i2 - 1) / total;
    }

    flag[left][i1][i2] = 1;
    return ret;
}

class KthProbableElement {
public:
    double probability(int _M, int lowerBound, int upperBound, int _N, int _K) {
        M = _M, N = _N, K = _K;
        total = upperBound - lowerBound + 1;
        m1 = N - lowerBound, m2 = upperBound - N;

        memset(flag, 0, sizeof(flag));

        double res = 0.0;
        FOR(i,1,K) {
            FOR(j,K,M) {
                res += dp(M, i, j);
            }
        }

        return res;
    }
};

// By ploh
/*class KthProbableElement {
public:
    double calc(int M, int LB, int UB, int N, int K) {
        double p = (N - LB + 1.0) / (UB - LB + 1);
        double ans = 0;
        FOR(i,K,M) {
            double binom = 1;
            REP(j,i) binom *= (M - j) / (j + 1.0);
            ans += binom * pow(p, i) * pow(1 - p, M - i);
        }
        return ans;
    }
    double probability(int M, int LB, int UB, int N, int K) {
        return calc(M, LB, UB, N, K) - calc(M, LB, UB, N - 1, K);
    }
};*/
// BEGIN CUT HERE
int main() {
    {
        KthProbableElement theObject;
        eq(0, theObject.probability(2, 1, 3, 2, 2),1.0/3);
    }
    {
        KthProbableElement theObject;
        eq(0, theObject.probability(1, 1, 10, 3, 1),0.1);
    }
    {
        KthProbableElement theObject;
        eq(1, theObject.probability(3, 1, 2, 2, 2),0.5);
    }
    {
        KthProbableElement theObject;
        eq(2, theObject.probability(3, 1, 3, 2, 2),0.48148148148148145);
    }
    {
        KthProbableElement theObject;
        eq(3, theObject.probability(10, 1, 10, 1, 10),1.0000000000000003E-10);
    }
    {
        KthProbableElement theObject;
        eq(4, theObject.probability(4, 61, 65, 62, 3),0.15200000000000002);
    }
    return 0;
}
// END CUT HERE
