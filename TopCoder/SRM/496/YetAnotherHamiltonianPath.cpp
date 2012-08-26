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

class YetAnotherHamiltonianPath {
public:
    int leastCost(vector <string> label) {
        int res = 0;
        int n = label.size();
        REP(i,n) {
            res += (i <= 1 ? 1 : 2) * label[i].length() * label[i].length();
        }
        int lcp0 = lcp(label[0], label[1]);
        sort(label.begin(), label.end());
        REP(i,n) {
            int t = lcp(label[i], label[(i + 1) % n]);
            res -= t * t;
        }
        res += lcp0 * lcp0;
        return res;
    }

    int lcp(string s1, string s2) {
        int res = 0;
        for (int i = 0; i < s1.length() && i < s2.length() && s1[i] == s2[i]; ++i, ++res) {}
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string labelARRAY[] = {"home", "school", "pub"} ;
        vector <string> label( labelARRAY, labelARRAY+ARRSIZE(labelARRAY) );
        YetAnotherHamiltonianPath theObject;
        eq(0, theObject.leastCost(label),70);
    }
    {
        string labelARRAY[] = {"school", "home", "pub", "stadium"};
        vector <string> label( labelARRAY, labelARRAY+ARRSIZE(labelARRAY) );
        YetAnotherHamiltonianPath theObject;
        eq(1, theObject.leastCost(label),167);
    }
    {
        string labelARRAY[] = {"abcd","aecgh","abef","aecd"};
        vector <string> label( labelARRAY, labelARRAY+ARRSIZE(labelARRAY) );
        YetAnotherHamiltonianPath theObject;
        eq(2, theObject.leastCost(label),91);
    }
    {
        string labelARRAY[] = {"canada", "cyprus", "croatia", "colombia", "chile", "china", "cameroon"};
        vector <string> label( labelARRAY, labelARRAY+ARRSIZE(labelARRAY) );
        YetAnotherHamiltonianPath theObject;
        eq(3, theObject.leastCost(label),509);
    }
    return 0;
}
// END CUT HERE
