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

bool isok(string s) {
    int v[26];
    memset(v, 0, sizeof(v));
    char last = s[0];
    REP(i,s.length()) {
        if (s[i] == last) continue;
        else {
            if (v[last - 'a'] == 1) return false;
            v[last - 'a'] = 1;
            last = s[i];
        }
    }
    if (v[last - 'a'] == 1) return false;
    return true;
}

int mm[55][55];
int vv[55];

class GroupedWord {
public:
    string restore(vector <string> parts) {
        int n = parts.size();

        REP(i,n) if (!isok(parts[i])) return "IMPOSSIBLE";

        memset(mm, 0, sizeof(mm));
        memset(vv, 0, sizeof(vv));

        REP(i,n) {
            int leni = parts[i].length();
            if (parts[i][0] != parts[i][leni - 1]) continue;
            REP(j,n) {
                if (i == j) continue;
                if (vv[j] == 1) continue;

                int lenj = parts[j].length();

                if (parts[i][0] == parts[j][lenj - 1]) {
                    parts[j] = parts[j] + parts[i];
                    vv[i] = 1;
                    break;
                } else if (parts[i][leni - 1] == parts[j][0]) {
                    parts[j] = parts[i] + parts[j];
                    vv[i] = 1;
                    break;
                }
            }
        }

        bool flag = false;
        while (true) {
            flag = false;
            REP(i,n) {
                if (vv[i] == 1) continue;

                int leni = parts[i].length();
                FOR(j,i+1,n-1) {
                    if (vv[j] == 1) continue;

                    int lenj = parts[j].length();

                    if (parts[i][0] == parts[j][lenj - 1]) {
                        parts[i] = parts[j] + parts[i];
                        vv[j] = 1;
                        flag = true;
                    } else if (parts[i][leni - 1] == parts[j][0]) {
                        parts[i] = parts[i] + parts[j];
                        vv[j] = 1;
                        flag = true;
                    }
                }
            }
            if (!flag) break;
        }

        vector<string> tmp;
        REP(i,n) if (vv[i] == 0) {
            tmp.push_back(parts[i]);
        }
        parts = tmp;

        REP(i,parts.size()) {
            if (!isok(parts[i])) return "IMPOSSIBLE";
        }

        REP(i,parts.size()) {
            FOR(j,i+1,parts.size()-1) {
                string a = parts[i], b = parts[j];
                int lena = a.length(), lenb = b.length();
                REP(i,lena) {
                    REP(j,lenb) {
                        if (a[i] == b[j]) return "IMPOSSIBLE";
                    }
                }
            }
        }

        if (parts.size() != 1) return "MANY";

        string res = parts[0];
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string partsARRAY[] = {"aaa", "a", "aa"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(0, theObject.restore(parts),"aaaaaa");
    }
    {
        string partsARRAY[] = {"ab", "bba"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(1, theObject.restore(parts),"IMPOSSIBLE");
    }
    {
        string partsARRAY[] = {"te", "st"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(2, theObject.restore(parts),"stte");
    }
    {
        string partsARRAY[] = {"te", "s", "t"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(3, theObject.restore(parts),"MANY");
    }
    {
        string partsARRAY[] = {"orr", "rd", "woo", "www"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(4, theObject.restore(parts),"wwwwooorrrd");
    }
    {
        string partsARRAY[] = {"abcb"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(5, theObject.restore(parts),"IMPOSSIBLE");
    }
    {
        string partsARRAY[] = {"aabb", "bbcc", "ccaa"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(6, theObject.restore(parts),"IMPOSSIBLE");
    }
    
    {
        string partsARRAY[] = {"ab", "bc", "bbb"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(7, theObject.restore(parts),"abbbbbc");
    }
    {
        string partsARRAY[] = {"abc", "bcd"};
        vector <string> parts( partsARRAY, partsARRAY+ARRSIZE(partsARRAY) );
        GroupedWord theObject;
        eq(8, theObject.restore(parts),"IMPOSSIBLE");
    }
    return 0;
}
// END CUT HERE
