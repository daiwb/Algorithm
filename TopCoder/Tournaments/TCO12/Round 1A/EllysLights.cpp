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
vector<vector<int> > mm;
vector<int> st;
string init;
int n, m, res;

class EllysLights {
public:
    void dfs(int idx, int num) {
        if (idx == n) {
            res = min(res, num);
            return;
        }
        if (num >= res) return;
        vector<int> bak = st;
        vector<int> sw = mm[idx];
        int sz = sw.size();
        if (init[idx] == 'Y') {
            if (sz == 0) return;
            else if (sz == 1) {
                if (st[sw[0]] == -1) return;
                else if (st[sw[0]] == 0) {
                    st[sw[0]] = 1;
                    dfs(idx + 1, num + 1);
                    st = bak;
                } else dfs(idx + 1, num);
            } else {
                if (st[sw[0]] != -1 && st[sw[1]] != 1) {
                    int tn = num;
                    if (st[sw[0]] == 0) {
                        st[sw[0]] = 1;
                        ++tn;
                    }
                    if (st[sw[1]] == 0) st[sw[1]] = -1;
                    dfs(idx + 1, tn);
                    st = bak;
                }
                if (st[sw[0]] != 1 && st[sw[1]] != -1) {
                    int tn = num;
                    if (st[sw[0]] == 0) st[sw[0]] = -1;
                    if (st[sw[1]] == 0) {
                        st[sw[1]] = 1;
                        ++tn;
                    }
                    dfs(idx + 1, tn);
                    st = bak;
                }
            }
        } else {
            if (sz == 0) dfs(idx + 1, num);
            else if (sz == 1) {
                if (st[sw[0]] == 1) return;
                else if (st[sw[0]] == 0) {
                    st[sw[0]] = -1;
                    dfs(idx + 1, num);
                    st = bak;
                }
                else dfs(idx + 1, num);
            } else {
                if (st[sw[0]] != 1 && st[sw[1]] != 1) {
                    int tn = num;
                    REP(i,2) {
                        if (st[sw[i]] == 0) st[sw[i]] = -1;
                    }
                    dfs(idx + 1, tn);
                    st = bak;
                }
                if (st[sw[0]] != -1 && st[sw[1]] != -1) {
                    int tn = num;
                    REP(i,2) {
                        if (st[sw[i]] == 0) {
                            st[sw[i]] = 1;
                            ++tn;
                        }
                    }
                    dfs(idx + 1, tn);
                    st = bak;
                }
            }
        }
    }
    int getMinimum(string initial, vector <string> switches) {
        sort(switches.begin(), switches.end());
        switches.erase(unique(switches.begin(), switches.end()), switches.end());
        init = initial;
        n = init.length();
        m = switches.size();
        mm.clear();
        mm.assign(n, vector<int>());
        REP(i,m) {
            REP(j,n) {
                if (switches[i][j] == 'Y') mm[j].push_back(i);
            }
        }
        res = m + 1;
        st.clear();
        st.assign(m, 0);
        dfs(0, 0);
        if (res == m + 1) res = -1;
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string switchesARRAY[] = {"YYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYY", "YYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYY"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(0, theObject.getMinimum("YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", switches),25);
    }
    {
        string switchesARRAY[] = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(0, theObject.getMinimum("YNYNNN", switches),2);
    }
    {
        string switchesARRAY[] = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(1, theObject.getMinimum("YNYNYN", switches),4);
    }
    {
        string switchesARRAY[] = {"YNY", "NYN"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(2, theObject.getMinimum("YYN", switches),-1);
    }
    {
        string switchesARRAY[] = {"NYNYNYNYNYNYNYNY",
            "YNYNYNYNYNYNYNYN",
            "NNNNNNNNNNNNNNNN",
            "YNNNNNNNNNNNNNNN",
            "NYNNNNNNNNNNNNNN",
            "NNYNNNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNN",
            "NNNNYNNNNNNNNNNN",
            "NNNNNYNNNNNNNNNN",
            "NNNNNNYNNNNNNNNN",
            "NNNNNNNYNNNNNNNN",
            "NNNNNNNNYNNNNNNN",
            "NNNNNNNNNYNNNNNN",
            "NNNNNNNNNNYNNNNN",
            "NNNNNNNNNNNYNNNN",
            "NNNNNNNNNNNNYNNN",
            "NNNNNNNNNNNNNYNN",
            "NNNNNNNNNNNNNNYN",
            "NNNNNNNNNNNNNNNY"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(3, theObject.getMinimum("NNYNYNYYYNNYYYYN", switches),6);
    }
    {
        string switchesARRAY[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
            "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
            "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
            "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
            "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
            "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
            "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
            "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
            "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
            "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
            "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(4, theObject.getMinimum("NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY", switches),7);
    }
    {
        string switchesARRAY[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
            "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
            "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
            "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
            "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
            "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
            "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
            "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
            "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
            "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
            "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
            "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
            "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
            "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(5, theObject.getMinimum("NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN", switches),-1);
    }
    return 0;
}
// END CUT HERE
