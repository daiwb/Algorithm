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

int hh[105][105], vv[105][105];

class TheMatrix {
public:
    int MaxArea(vector <string> board) {
        int n = board.size(), m = board[0].length();
        REP(i,n) {
            REP(j,m) {
                hh[i][j] = 1;
                FOR(ii,j+1,m-1) {
                    if (board[i][ii] != board[i][ii - 1]) ++hh[i][j];
                    else break;
                }
                vv[i][j] = 1;
                FOR(ii,i+1,n-1) {
                    if (board[ii][j] != board[ii - 1][j]) ++vv[i][j];
                    else break;
                }
            }
        }

        int res = 1;
        REP(i,n) {
            REP(j,m) {
                if ((n - i) * (m - j) <= res) continue;
                int t = vv[i][j];
                REP(ii,hh[i][j]) {
                    t = min(t, vv[i][j + ii]);
                    res = max(res, t * (ii + 1));
                }
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string boardARRAY[] = {"1", 
            "0"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(0, theObject.MaxArea(board),2);
    }
    {
        string boardARRAY[] = {"0000"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(1, theObject.MaxArea(board),1);
    }
    {
        string boardARRAY[] = {"01"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(2, theObject.MaxArea(board),2);
    }
    {
        string boardARRAY[] = {"001",
            "000",
            "100"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(3, theObject.MaxArea(board),2);
    }
    {
        string boardARRAY[] = {"0"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(4, theObject.MaxArea(board),1);
    }
    {
        string boardARRAY[] = {"101", 
            "010"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(5, theObject.MaxArea(board),6);
    }
    {
        string boardARRAY[] = {"101", 
            "011", 
            "101", 
            "010"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(6, theObject.MaxArea(board),8);
    }
    {
        string boardARRAY[] = {"11001110011000110001111001001110110011010110001011", 
            "10100100010111111011111001011110101111010011100001", 
            "11101111001110100110010101101100011100101000010001", 
            "01000010001010101100010011111000100100110111111000", 
            "10110100000101100000111000100001011101111101010010", 
            "00111010000011100001110110010011010110010011100100", 
            "01100001111101001101001101100001111000111001101010", 
            "11010000000011011010100010000000111011001001100101", 
            "10100000000100010100100011010100110110110001000001", 
            "01101010101100001100000110100110100000010100100010", 
            "11010000001110111111011010011110001101100011100010", 
            "11101111000000011010011100100001100011111111110111", 
            "11000001101100100011000110111010011001010100000001", 
            "00100001111001010000101101100010000001100100001000", 
            "01001110110111101011010000111111101011000110010111", 
            "01001010000111111001100000100010101100100101010100", 
            "11111101001101110011011011011000111001101100011011", 
            "10000100110111000001110110010000000000111100101101", 
            "01010011101101101110000011000110011111001111011100", 
            "01101010011111010000011001111101011010011100001101", 
            "11011000011000110010101111100000101011011111101100", 
            "11100001001000110010100011001010101101001010001100", 
            "11011011001100111101001100111100000101011101101011", 
            "11110111100100101011100101111101000111001111110111", 
            "00011001100110111100111100001100101001111100001111", 
            "10001111100101110111001111100000000011110000100111", 
            "10101010110110100110010001001010000111100110100011", 
            "01100110100000001110101001101011001010001101110101", 
            "10110101110100110110101001100111110000101111100110", 
            "01011000001001101110100001101001110011001001110001", 
            "00100101010001100110110101001010010100001011000011", 
            "00011101100100001010100000000011000010100110011100", 
            "11001001011000000101111111000000110010001101101110", 
            "10101010110110010000010011001100110101110100111011", 
            "01101001010111010001101000100011101001110101000110", 
            "00110101101110110001110101110010100100110000101101", 
            "11010101000111010011110011000001101111010011110011", 
            "10010000010001110011011101001110110010001100011100", 
            "00111101110001001100101001110100110010100110110000", 
            "00010011011000101000100001101110111100100000010100", 
            "01101110001101000001001000001011101010011101011110", 
            "00000100110011001011101011110011011101100001110111", 
            "00110011110000011001011100001110101010100110010110", 
            "00111001010011011111010100000100100000101101110001", 
            "10101101101110111110000011111011001011100011110001", 
            "00101110010101111000001010110100001110111011100011", 
            "01111110010100111010110001111000111101110100111011"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheMatrix theObject;
        eq(7, theObject.MaxArea(board),12);
    }
    return 0;
}
// END CUT HERE
