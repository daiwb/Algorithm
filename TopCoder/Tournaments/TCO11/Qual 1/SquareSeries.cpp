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

// By {dano} @TopCoder

int eval(const string &s) {
    int val = 1;
    FOR(i,1,(int)s.size()-1) {
        if (s[i] == s[i - 1]) {
            --val;
            if (val == 0) return -1;
        } else ++val;
    }
    return val;
}

string bef,aft;

bool vis[2][200];
deque<string> q;

void add(string s){
    int v = eval(bef + s);
    if (v == -1 || v >= 200) return;
    int i1 = s[s.size() - 1] == 'W' ? 1 : 0;

    if (vis[i1][v]) return;
    vis[i1][v] = true;
    q.push_back(s);
}

class SquareSeries {
public:
    string completeIt(string pattern, int lastLength) {
        if (pattern == "?" && lastLength == 1) return "B";
        int idx = pattern.find('?');
        bef = pattern.substr(0, idx);
        aft = pattern.substr(idx + 1);
        if (eval(bef) == -1) return "...";
        if (eval(bef + aft) == lastLength) return bef + aft;

        q.clear();
        memset(vis, 0, sizeof(vis));
        add("B");
        add("W");
        while(!q.empty()){
            string s = q.front();
            q.pop_front();
            if (eval(bef + s + aft) == lastLength) return bef + s + aft;
            add(s + "B");
            add(s + "W");
        }
        return "...";
    }
};
// BEGIN CUT HERE
int main() {
    {
        SquareSeries theObject;
        eq(0, theObject.completeIt("W?B", 2),"WB");
    }
    {
        SquareSeries theObject;
        eq(1, theObject.completeIt("?", 5),"BWBWB");
    }
    {
        SquareSeries theObject;
        eq(2, theObject.completeIt("BWBBBBW?WB", 10),"...");
    }
    {
        SquareSeries theObject;
        eq(3, theObject.completeIt("BWBWBW?WBWBWBW", 15),"BWBWBWBBWBWBWBWBW");
    }
    {
        SquareSeries theObject;
        eq(4, theObject.completeIt("WBWBWBWBWBWWBB?W", 1),"WBWBWBWBWBWWBBBBBBBBBBBWW");
    }
    {
        SquareSeries theObject;
        eq(5, theObject.completeIt("?WBWBWBBB", 3),"...");
    }
    return 0;
}
// END CUT HERE
