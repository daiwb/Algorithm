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
#define PB push_back
#define MP make_pair
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

class ColoredStrokes {
public:
    int getLeast(vector <string> picture) {
        int res = 0;
        int h = picture.size(), w = picture[0].length();
        REP(i,h) {
            bool fg = false;
            REP(j,w) {
                if (picture[i][j] == 'R' || picture[i][j] == 'G') {
                    if (!fg) {
                        ++res;
                        fg = true;
                    }
                } else {
                    fg = false;
                }
            }
        }

        REP(j,w) {
            bool fg = false;
            REP(i,h) {
                if (picture[i][j] == 'B' || picture[i][j] == 'G') {
                    if (!fg) {
                        ++res;
                        fg = true;
                    }
                } else {
                    fg = false;
                }
            }
        }
        
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string pictureARRAY[] = {"...",
            "..."};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        ColoredStrokes theObject;
        eq(0, theObject.getLeast(picture),0);
    }
    {
        string pictureARRAY[] = {"..B.",
            "..B."};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        ColoredStrokes theObject;
        eq(1, theObject.getLeast(picture),1);
    }
    {
        string pictureARRAY[] = {".BB."};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        ColoredStrokes theObject;
        eq(2, theObject.getLeast(picture),2);
    }
    {
        string pictureARRAY[] = {"...B..",
            ".BRGRR",
            ".B.B.."};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        ColoredStrokes theObject;
        eq(3, theObject.getLeast(picture),3);
    }
    {
        string pictureARRAY[] = {"...B..",
            ".BRBRR",
            ".B.B.."};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        ColoredStrokes theObject;
        eq(4, theObject.getLeast(picture),4);
    }
    {
        string pictureARRAY[] = {"GR",
            "BG"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        ColoredStrokes theObject;
        eq(5, theObject.getLeast(picture),4);
    }
    return 0;
}
// END CUT HERE
