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
int sum[45][45];

class ComplementMachine2D {
public:
    int largestSubmatrix(vector <string> mat) {
        int r = mat.size(), c = mat[0].size();
        int res = 1;
        REP(r1,r) {
            FOR(r2,r1,r-1) {
                int d = r2 - r1 + 1;
                int cnt = 1;
                FOR(cc,1,c-1) {
                    int s = 0;
                    FOR(rr,r1,r2) {
                        if (mat[rr][cc] == mat[rr][cc - 1]) ++s;
                    }
                    if (s == 0 || s == d) {
                        ++cnt;
                        res = max(res, cnt * d);
                    } else {
                        cnt = 1;
                    }
                }
            }
        }
        REP(c1,c) {
            FOR(c2,c1,c-1) {
                int d = c2 - c1 + 1;
                int cnt = 1;
                FOR(rr,1,r-1) {
                    int s = 0;
                    FOR(cc,c1,c2) {
                        if (mat[rr][cc] == mat[rr - 1][cc]) ++s;
                    }
                    if (s == 0 || s == d) {
                        ++cnt;
                        res = max(res, cnt * d);
                    } else {
                        cnt = 1;
                    }
                }
            }
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string matrixARRAY[] = {"0011",
            "0011",
            "1100",
            "0111"};
        vector <string> matrix( matrixARRAY, matrixARRAY+ARRSIZE(matrixARRAY) );
        ComplementMachine2D theObject;
        eq(0, theObject.largestSubmatrix(matrix),12);
    }
    {
        string matrixARRAY[] = {"0011",
            "1011",
            "0101",
            "1010"};
        vector <string> matrix( matrixARRAY, matrixARRAY+ARRSIZE(matrixARRAY) );
        ComplementMachine2D theObject;
        eq(1, theObject.largestSubmatrix(matrix),9);
    }
    {
        string matrixARRAY[] = {"1011",
            "0011",
            "0101",
            "1010"};
        vector <string> matrix( matrixARRAY, matrixARRAY+ARRSIZE(matrixARRAY) );
        ComplementMachine2D theObject;
        eq(2, theObject.largestSubmatrix(matrix),8);
    }
    {
        string matrixARRAY[] = {"0000110101010",
            "0111101010111",
            "1110110111011"};
        vector <string> matrix( matrixARRAY, matrixARRAY+ARRSIZE(matrixARRAY) );
        ComplementMachine2D theObject;
        eq(3, theObject.largestSubmatrix(matrix),13);
    }
    {
        string matrixARRAY[] = {"11000000000110101101",
            "00111111011101101101",
            "00110011110111100010",
            "10011110111110000111",
            "00111010000000110111",
            "00001101011011010110",
            "11010010100100101100",
            "11101101011011000001",
            "11000010100100111001",
            "11011010100100101010",
            "10110010100100110110",
            "01100010100100111001",
            "10110010100100110011",
            "01110101011011001010",
            "01111101011011001011",
            "00001000010010101011",
            "11100101100100110001",
            "10100100111001010101",
            "11111000001010011110",
            "01110100001110011111"}
           ;
        vector <string> matrix( matrixARRAY, matrixARRAY+ARRSIZE(matrixARRAY) );
        ComplementMachine2D theObject;
        eq(4, theObject.largestSubmatrix(matrix),100);
    }
    {
        string matrixARRAY[] = {"11000000000110101101",
            "00111111011101101101",
            "00110011110111100010",
            "10011110111110000111",
            "00111010000000110111",
            "00001101010011010110",
            "11011010100100101100",
            "11101101011011000001",
            "11000010100100111001",
            "11011010101100101010",
            "10110010100100110110",
            "01100010100100111001",
            "10110010100100110011",
            "01110101001011001010",
            "01111101011011001011",
            "00001000010010101011",
            "11100101100100110001",
            "10100100111001010101",
            "11111000001010011110",
            "01110100001110011111"}
           ;
        vector <string> matrix( matrixARRAY, matrixARRAY+ARRSIZE(matrixARRAY) );
        ComplementMachine2D theObject;
        eq(4, theObject.largestSubmatrix(matrix),40);
    }
    return 0;
}
// END CUT HERE
