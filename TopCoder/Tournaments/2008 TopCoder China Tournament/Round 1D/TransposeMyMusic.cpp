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

// END CUT HERE

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


// END CUT HERE

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

string base[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
string minor[12] = {"Am", "A#m", "Bm", "Cm", "C#m", "Dm", "D#m", "Em", "Fm", "F#m", "Gm", "G#m"};
string flat[12] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"};

bool isflat(string str) {
    if (str == "F" || str == "Fm") return true;
    REP(i,str.length()) {
        if (str[i] == 'b') return true;
    }
    return false;
}

bool isminor(string str) {
    REP(i,str.length()) {
        if (str[i] == 'm') return true;
    }
    return false;
}

int getidx(string str) {
    REP(i,12) {
        if (base[i] == str) return i;
        if (base[i] + "m" == str) return i;
        if (flat[i] == str) return i;
        if (flat[i] + "m" == str) return i;
    }
    return -1;
}

class TransposeMyMusic {
public:
    string transposeMusic(vector <string> sheetMusic, string newKey) {
        string str = "";
        REP(i,sheetMusic.size()) str += sheetMusic[i];
        vector<string> mm = split(str, " ");
        string first = mm[0];
        bool fl = isflat(newKey);

        int i1 = getidx(first), i2 = getidx(newKey);
        int d = (i2 - i1 + 12) % 12;

        string res = "";

        REP(i,mm.size()) {
            if (i > 0) res += " ";
            if (mm[i] == "|") res += "|";
            else {
                int idx = getidx(mm[i]);
                idx = (idx + d) % 12;
                string s;
                if (fl) s = flat[idx];
                else s = base[idx];
                if (isminor(mm[i])) s += "m";
                res += s;
            }
        }

        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string sheetMusicARRAY[] = {"G D Am | G D C | G D Am | G D C"};
        vector <string> sheetMusic( sheetMusicARRAY, sheetMusicARRAY+ARRSIZE(sheetMusicARRAY) );
        TransposeMyMusic theObject;
        eq(0, theObject.transposeMusic(sheetMusic, "F"),"F C Gm | F C Bb | F C Gm | F C Bb");
    }
    {
        string sheetMusicARRAY[] = {"A Bb B C Db D Eb E F Gb G Ab"};
        vector <string> sheetMusic( sheetMusicARRAY, sheetMusicARRAY+ARRSIZE(sheetMusicARRAY) );
        TransposeMyMusic theObject;
        eq(1, theObject.transposeMusic(sheetMusic, "A"),"A A# B C C# D D# E F F# G G#");
    }
    {
        string sheetMusicARRAY[] = {"C G Am F | C G F C Dm C | C G A",
           "m F | G F C Dm C | Am F G ",
           "F C Dm C"};
        vector <string> sheetMusic( sheetMusicARRAY, sheetMusicARRAY+ARRSIZE(sheetMusicARRAY) );
        TransposeMyMusic theObject;
        eq(2, theObject.transposeMusic(sheetMusic, "F#"),"F# C# D#m B | F# C# B F# G#m F# | F# C# D#m B | C# B F# G#m F# | D#m B C# B F# G#m F#");
    }
    {
        string sheetMusicARRAY[] = {"A# | | | Bb"};
        vector <string> sheetMusic( sheetMusicARRAY, sheetMusicARRAY+ARRSIZE(sheetMusicARRAY) );
        TransposeMyMusic theObject;
        eq(3, theObject.transposeMusic(sheetMusic, "G#"),"G# | | | G#");
    }
    {
        string sheetMusicARRAY[] = {"Gm C Gm | Eb D C Gm | Gm C Gm"};
        vector <string> sheetMusic( sheetMusicARRAY, sheetMusicARRAY+ARRSIZE(sheetMusicARRAY) );
        TransposeMyMusic theObject;
        eq(4, theObject.transposeMusic(sheetMusic, "Dbm"),"Dbm Gb Dbm | A Ab Gb Dbm | Dbm Gb Dbm");
    }
    return 0;
}
// END CUT HERE
