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

// END CUT HERE

LL s2i(string s) {
    stringstream ss;
    ss << s;
    LL res;
    ss >> res;
    return res;
}

string i2s(LL n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

bool isdups(string str) {
    FOR(i,1,str.length()-1) {
        if (str[i] == str[i - 1]) return true;
    }
    return false;
}

bool isdup(LL n) {
    string str = i2s(n);
    return isdups(str);
}

class UnrepeatingNumbers {
public:
    long long getNext(long long A) {
        string str = i2s(A);
        RFOR(i,str.length()-2,-1) {
            int s = str[i + 1] - '0';
            FOR(j,s+1,9) {
                string sub = str.substr(0, i + 1);
                sub += char(j + '0');
                if (isdups(sub)) continue;
                while (sub.length() < str.length()) {
                    if (sub[sub.length() - 1] == '0') sub += "1";
                    else sub += "0";
                }
                LL res = s2i(sub);
                return res;
            }
        }
        string ret = "1";
        while (ret.length() < str.length() + 1) {
            if (ret[ret.length() - 1] == '0') ret += "1";
            else ret += "0";
        }
        long long res = s2i(ret);
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        UnrepeatingNumbers theObject;
        eq(0, theObject.getNext(54L),56LL);
    }
    {
        UnrepeatingNumbers theObject;
        eq(1, theObject.getNext(10L),12LL);
    }
    {
        UnrepeatingNumbers theObject;
        eq(2, theObject.getNext(9L),10LL);
    }
    {
        UnrepeatingNumbers theObject;
        eq(3, theObject.getNext(98L),101LL);
    }
    {
        UnrepeatingNumbers theObject;
        eq(4, theObject.getNext(21099L),21201LL);
    }
    return 0;
}
// END CUT HERE
