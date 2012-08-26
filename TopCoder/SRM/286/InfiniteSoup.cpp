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

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        a ^= b ^= a ^= b;
    }
    return a;
}

vector<vector<int> > suffixes;

vector<int> BuildSuffix(string pattern) {
    int lp = pattern.length();
    vector<int> pi(lp, -1);
    int k = -1;
    FOR(q,1,lp-1) {
        while (k >= 0 && pattern[k + 1] != pattern[q]) k = pi[k];
        if (pattern[k + 1] == pattern[q]) ++k;
        pi[q] = k;
    }
    return pi;
}

bool StringMatchKMP(string text, string pattern, vector<int> suffix) {
    int lt = text.length(), lp = pattern.length();
    int k = -1;
    REP(i,lt) {
        while (k >= 0 && pattern[k + 1] != text[i]) k = suffix[k];
        if (pattern[k + 1] == text[i]) ++k;
        if (k == lp - 1) return true;
    }
    return false;
}

int cnt[40][40];

class InfiniteSoup {
public:
    vector <int> countRays(vector <string> g, vector <string> words, int k) {
        int r = g.size(), c = g[0].length();

        suffixes.clear();
        REP(i,words.size()) suffixes.push_back(BuildSuffix(words[i]));

        memset(cnt, 0, sizeof(cnt));
        FOR(i,0,k) {
            FOR(j,0,k) {
                if (gcd(i, j) == 1) ++cnt[i % r][j % c];
            }
        }

        vector <int> res(words.size(), 0);

        REP(i,r) {
            REP(j,c) {
                if (cnt[i][j] > 0) {
                    string str = "";
                    int tr = 0, tc = 0;
                    do {
                        str += g[tr][tc];
                        tr = (tr + i) % r, tc = (tc + j) % c;
                    } while (tr || tc);

                    string t = str;
                    REP(k,50) t += str[k % str.length()];

                    REP(k,words.size()) {
                        if (StringMatchKMP(t, words[k], suffixes[k])) res[k] += cnt[i][j];
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
        string gARRAY[] = {"abc","def","ghi"};
        vector <string> g( gARRAY, gARRAY+ARRSIZE(gARRAY) );
        string wordsARRAY[] = {"abc"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        int retrunValueARRAY[] = {1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        InfiniteSoup theObject;
        eq(0, theObject.countRays(g, words, 2),retrunValue);
    }
    {
        string gARRAY[] = {"abc","def","ghi"};
        vector <string> g( gARRAY, gARRAY+ARRSIZE(gARRAY) );
        string wordsARRAY[] = {"abc"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        int retrunValueARRAY[] = {2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        InfiniteSoup theObject;
        eq(1, theObject.countRays(g, words, 3),retrunValue);
    }
    {
        string gARRAY[] = {"abc","def","ghi"};
        vector <string> g( gARRAY, gARRAY+ARRSIZE(gARRAY) );
        string wordsARRAY[] = {"abc"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        int retrunValueARRAY[] = {3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        InfiniteSoup theObject;
        eq(2, theObject.countRays(g, words, 4),retrunValue);
    }
    {
        string gARRAY[] = {"ccbbc","baabc","ccbab","cbcaa","aacab"};
        vector <string> g( gARRAY, gARRAY+ARRSIZE(gARRAY) );
        string wordsARRAY[] = {"aaccbaaccbaacc","aabbcaabbcaabbc","babccbabccbabc","aaacaaaacaaaaca",
            "abbcaabbcaab","ccbbcccbbcccbbc","bbacabbacab","caacccaacccaac",
            "baaccbaaccbaac","caccbcaccbca"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        int retrunValueARRAY[] = {0, 2, 0, 0, 2, 7, 5, 6, 0, 5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        InfiniteSoup theObject;
        eq(3, theObject.countRays(g, words, 10),retrunValue);
    }
    {
        string gARRAY[] = {"abb","bbb","bbb"};
        vector <string> g( gARRAY, gARRAY+ARRSIZE(gARRAY) );
        string wordsARRAY[] = {"aaa"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        int retrunValueARRAY[] = {0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        InfiniteSoup theObject;
        eq(4, theObject.countRays(g, words, 2),retrunValue);
    }
    return 0;
}
// END CUT HERE
