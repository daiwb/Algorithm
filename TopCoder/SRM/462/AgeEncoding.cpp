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
#define EPS 1e-10
int target;

double getVal(double base, string str) {
    int len = str.length();
    double b = 1.0;
    double t = 0.0;
    RFOR(i,len-1,0) {
        if (str[i] == '1') t += b;
        b *= base;
        if (t > target + EPS) break;
    }

    return t;
}

class AgeEncoding {
public:
    double getRadix(int age, string str) {
        target = age;
        while (str.length() > 1 && str[0] == '0') str = str.substr(1);
        
        double sum = getVal(100.0, str);
        if (sum < age - EPS) return -1.0;

        int cnt = 0;
        REP(i,str.length()) cnt += str[i] - '0';
        if (age == 1 && str[str.length() - 1] == '1') {
            if (cnt == 1) return -2.0;
            if (cnt >= 2) return -1.0;
        }

        double left = 0.0, right = 100.0, res = 0.0;
        while (true) {
            res = (left + right) / 2;
            double t = getVal(res, str);
            if (fabs(t - age) < EPS) break;
            if (t > age) right = res;
            else left = res;
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() { 
    {
        AgeEncoding theObject;
        eq(0, theObject.getRadix(1, "00000"),-1.0);
    }
    {
        AgeEncoding theObject;
        eq(0, theObject.getRadix(1, "11"),-1.0);
    }
    {
        AgeEncoding theObject;
        eq(0, theObject.getRadix(1, "00001"),-2.0);
    }
    {
        AgeEncoding theObject;
        eq(0, theObject.getRadix(10, "00010"),10.0);
    }
    {
        AgeEncoding theObject;
        eq(1, theObject.getRadix(21, "10101"),2.0);
    }
    {
        AgeEncoding theObject;
        eq(2, theObject.getRadix(6, "10100"),1.414213562373095);
    }
    {
        AgeEncoding theObject;
        eq(3, theObject.getRadix(21, "10111111110111101111111100111111110111111111111100"),0.9685012944510603);
    }
    {
        AgeEncoding theObject;
        eq(4, theObject.getRadix(16, "1"),-1.0);
    }
    {
        AgeEncoding theObject;
        eq(5, theObject.getRadix(1, "1"),-2.0);
    }
    {
        AgeEncoding theObject;
        eq(6, theObject.getRadix(1, "001000"),1.0);
    }
    return 0;
}
// END CUT HERE
