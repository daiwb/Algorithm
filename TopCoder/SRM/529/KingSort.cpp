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

map<string, int> mp1;
map<int, string> mp2;

class King {
public:
    string name;
    string strVal;
    int val;
    string ful;
    King(string _n, string _v, string _f) : name(_n), strVal(_v), ful(_f) {
        val = mp1[strVal];
    }
    bool operator<(const King& rhs) const {
        if (name != rhs.name) return name < rhs.name;
        return val < rhs.val;
    }
};

string mm[14] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XX", "XXX", "XL", "L"};
int dd[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50};

void init() {
    mp1.clear();
    mp2.clear();
    REP(i,14) {
        mp1[mm[i]] = dd[i];
        mp2[dd[i]] = mm[i];
    }

    for (int t = 10; t <= 40; t += 10) {
        FOR(i,1,9) {
            string s = mp2[t] + mp2[i];
            mp1[s] = t + i;
            mp2[t + i] = s;
        }
    }
}

class KingSort {
public:
    vector <string> getSortedList(vector <string> kings) {
        init();
        vector<King> ks;
        REP(i,kings.size()) {
            vector<string> parts = split(kings[i], " ");
            ks.push_back(King(parts[0], parts[1], kings[i]));
        }
        sort(ks.begin(), ks.end());
        vector <string> res;
        REP(i,ks.size()) {
            res.push_back(ks[i].ful);
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string kingsARRAY[] = {"Louis IX", "Louis VIII"};
        vector <string> kings( kingsARRAY, kingsARRAY+ARRSIZE(kingsARRAY) );
        string retrunValueARRAY[] = {"Louis VIII", "Louis IX" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KingSort theObject;
        eq(0, theObject.getSortedList(kings),retrunValue);
    }
    {
        string kingsARRAY[] = {"Louis IX", "Philippe II"};
        vector <string> kings( kingsARRAY, kingsARRAY+ARRSIZE(kingsARRAY) );
        string retrunValueARRAY[] = {"Louis IX", "Philippe II" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KingSort theObject;
        eq(1, theObject.getSortedList(kings),retrunValue);
    }
    {
        string kingsARRAY[] = {"Richard III", "Richard I", "Richard II"};
        vector <string> kings( kingsARRAY, kingsARRAY+ARRSIZE(kingsARRAY) );
        string retrunValueARRAY[] = {"Richard I", "Richard II", "Richard III" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KingSort theObject;
        eq(2, theObject.getSortedList(kings),retrunValue);
    }
    {
        string kingsARRAY[] = {"John X", "John I", "John L", "John V"};
        vector <string> kings( kingsARRAY, kingsARRAY+ARRSIZE(kingsARRAY) );
        string retrunValueARRAY[] = {"John I", "John V", "John X", "John L" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KingSort theObject;
        eq(3, theObject.getSortedList(kings),retrunValue);
    }
    {
        string kingsARRAY[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"};
        vector <string> kings( kingsARRAY, kingsARRAY+ARRSIZE(kingsARRAY) );
        string retrunValueARRAY[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KingSort theObject;
        eq(4, theObject.getSortedList(kings),retrunValue);
    }
    {
        string kingsARRAY[] = {"Philippe II", "Philip II"};
        vector <string> kings( kingsARRAY, kingsARRAY+ARRSIZE(kingsARRAY) );
        string retrunValueARRAY[] = {"Philip II", "Philippe II" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KingSort theObject;
        eq(5, theObject.getSortedList(kings),retrunValue);
    }
    return 0;
}
// END CUT HERE
