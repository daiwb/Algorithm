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
vector<int> score;
int C, S, N, tot, sum;

double doit(int idx) {
    double s1 = score[idx];
    double s2 = (sum - s1) / (N - 1);

    double all = tot * (tot - 1) / 2;
    double p2 = C * (N - 1) * C / all;
    double p1 = 1 - p2;

    FOR(i,1,S) {
        double ts1 = s1 * p1 + (s1 + (s2 - s1) / C) * p2;
        double ts2 = s2 * p1 + (s2 + (s1 - s2) / C / (N - 1)) * p2;

        s1 = ts1;
        s2 = ts2;
    }

    return s1;
}

class CandyBox {
public:
    vector <double> expectedScore(int _C, vector <int> _score, int _S) {
        score = _score;
        C = _C, S = _S, N = score.size();
        tot = C * N;
        sum = 0;
        REP(i,N) sum += score[i];
        vector <double> res;
        if (N == 1) {
            res.push_back(score[0]);
            return res;
        }
        REP(i,N) res.push_back(doit(i));
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        int scoreARRAY[] = {1, 10};
        vector <int> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        double retrunValueARRAY[] = {1.0, 10.0 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandyBox theObject;
        eq(0, theObject.expectedScore(10, score, 0),retrunValue);
    }
    {
        int scoreARRAY[] = {1, 10};
        vector <int> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        double retrunValueARRAY[] = {4.0, 7.000000000000001 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandyBox theObject;
        eq(1, theObject.expectedScore(2, score, 1),retrunValue);
    }
    {
        int scoreARRAY[] = {1, 4, 10};
        vector <int> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        double retrunValueARRAY[] = {5.0, 5.0, 5.0 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandyBox theObject;
        eq(2, theObject.expectedScore(1, score, 1),retrunValue);
    }
    {
        int scoreARRAY[] = {13, 82, 74, 78, 12, 71, 81, 80, 30};
        vector <int> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        double retrunValueARRAY[] = {26.25622829378155, 74.87969915903301, 69.24219529059805, 72.06094722481552, 25.551540310227182, 67.12813133993495, 74.17501117547864, 73.47032319192427, 38.23592401420582 };
        vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandyBox theObject;
        eq(3, theObject.expectedScore(98, score, 154),retrunValue);
    }
    return 0;
}
// END CUT HERE
