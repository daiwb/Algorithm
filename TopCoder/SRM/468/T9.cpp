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

int vv[55];
int idx, cnt;
string res;
vector<string> dict;

void doit() {
    if (cnt > 0) {
        vector<string> temp;
        REP(j,dict.size()) {
            if (vv[j] == 0 && dict[j].length() == cnt) {
                temp.push_back(dict[j]);
            }
        }
        sort(temp.begin(), temp.end());
        res += temp[idx % temp.size()];
        idx = 0, cnt = 0;
        memset(vv, 0, sizeof(vv));
    }
}

class T9 {
public:
    string message(vector <string> part, vector <string> _dict, vector <string> keystr) {
        dict = _dict;
        res = "";
        string str = "";
        REP(i,keystr.size()) str += keystr[i];
        memset(vv, 0, sizeof(vv));
        idx = 0, cnt = 0;
        REP(i,str.length()) {
            if (str[i] >= '1' && str[i] <= '9') {
                ++cnt;
                REP(j,dict.size()) {
                    if (vv[j] == 1) continue;
                    if (dict[j].length() < cnt) {
                        vv[j] = 1;
                        continue;
                    }
                    bool found = false;
                    int n = str[i] - '1';
                    REP(k,part[n].length()) {
                        if (part[n][k] == dict[j][cnt - 1]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) vv[j] = 1;
                }
            } else if (str[i] == '*' || str[i] == '#') {
                while (i < str.length() && (str[i] == '*' || str[i] == '#')) {
                    if (str[i] == '*') idx += 5;
                    else ++idx;
                    ++i;
                }

                doit();

                --i;
            } else if (str[i] == '0') {
                doit();

                res += " ";
            }
        }

        doit();

        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string partARRAY[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> part( partARRAY, partARRAY+ARRSIZE(partARRAY) );
        string dictARRAY[] = {"the", "tie", "ther"};
        vector <string> dict( dictARRAY, dictARRAY+ARRSIZE(dictARRAY) );
        string keystrARRAY[] = {"0843#000843#000"};
        vector <string> keystr( keystrARRAY, keystrARRAY+ARRSIZE(keystrARRAY) );
        T9 theObject;
        eq(0, theObject.message(part, dict, keystr)," tie   tie   ");
    }
    {
        string partARRAY[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> part( partARRAY, partARRAY+ARRSIZE(partARRAY) );
        string dictARRAY[] = {"bad"};
        vector <string> dict( dictARRAY, dictARRAY+ARRSIZE(dictARRAY) );
        string keystrARRAY[] = {"2230223"};
        vector <string> keystr( keystrARRAY, keystrARRAY+ARRSIZE(keystrARRAY) );
        T9 theObject;
        eq(0, theObject.message(part, dict, keystr),"bad bad");
    }
    {
        string partARRAY[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> part( partARRAY, partARRAY+ARRSIZE(partARRAY) );
        string dictARRAY[] = {"the", "tie"};
        vector <string> dict( dictARRAY, dictARRAY+ARRSIZE(dictARRAY) );
        string keystrARRAY[] = {"0843#000843#000"};
        vector <string> keystr( keystrARRAY, keystrARRAY+ARRSIZE(keystrARRAY) );
        T9 theObject;
        eq(1, theObject.message(part, dict, keystr)," tie   tie   ");
    }
    {
        string partARRAY[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> part( partARRAY, partARRAY+ARRSIZE(partARRAY) );
        string dictARRAY[] = {"bad", "ace", "aad", "aae", "aaf", "acf", "acd", "the", "tie"};
        vector <string> dict( dictARRAY, dictARRAY+ARRSIZE(dictARRAY) );
        string keystrARRAY[] = {"223#02", "23*#00843#0"};
        vector <string> keystr( keystrARRAY, keystrARRAY+ARRSIZE(keystrARRAY) );
        T9 theObject;
        eq(2, theObject.message(part, dict, keystr),"aae bad  tie ");
    }
    {
        string partARRAY[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> part( partARRAY, partARRAY+ARRSIZE(partARRAY) );
        string dictARRAY[] = {"the", "tie", "bad", "ace", "aad", "aae", "aaf", "acf", "acd"};
        vector <string> dict( dictARRAY, dictARRAY+ARRSIZE(dictARRAY) );
        string keystrARRAY[] = {"84300223#02", "23#*"};
        vector <string> keystr( keystrARRAY, keystrARRAY+ARRSIZE(keystrARRAY) );
        T9 theObject;
        eq(3, theObject.message(part, dict, keystr),"the  aae bad");
    }
    {
        string partARRAY[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> part( partARRAY, partARRAY+ARRSIZE(partARRAY) );
        string dictARRAY[] = {"bad", "ace", "aad", "aae", "tie", "aaf", "acf", "acd", "the"};
        vector <string> dict( dictARRAY, dictARRAY+ARRSIZE(dictARRAY) );
        string keystrARRAY[] = {"223#02", "23######"};
        vector <string> keystr( keystrARRAY, keystrARRAY+ARRSIZE(keystrARRAY) );
        T9 theObject;
        eq(4, theObject.message(part, dict, keystr),"aae bad");
    }
    {
        string partARRAY[] = {"", "rq", "lde", "yoauz", "cbfgn", "tjkpx", "wvs", "ih", "m"};
        vector <string> part( partARRAY, partARRAY+ARRSIZE(partARRAY) );
        string dictARRAY[] = {"xktgmfmoqlmivm",
            "hmthr", 
            "tpjgmnmaremiwm", 
            "tpjcmnmyrlmhvm", 
            "xkpnmgmzqdmhsm", 
            "wqopvvmiig", 
            "melbcbqeeg", 
            "jkxnmbmardmhwm", 
            "kpxnmcmyqlmism", 
            "wrztvsmhhf", 
            "srztssmiic", 
            "pxtgmfmyrdmhwm", 
            "vqoxswmiin", 
            "wryksvmihb", 
            "ptjfmbmoremhvm"};
        vector <string> dict( dictARRAY, dictARRAY+ARRSIZE(dictARRAY) );
        string keystrARRAY[] = {"00", 
            "7246779885##00000089682000007246779885##0000724677", 
            "9885#000089682000093355523350066659594239879###000"};
        vector <string> keystr( keystrARRAY, keystrARRAY+ARRSIZE(keystrARRAY) );
        T9 theObject;
        eq(5, theObject.message(part, dict, keystr),"  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   ");
    }
    return 0;
}
// END CUT HERE
