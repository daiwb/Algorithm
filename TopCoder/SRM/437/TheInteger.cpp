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

int vv[10];

int getCount(string s) {
    int len = s.length();
    memset(vv, 0, sizeof(vv));
    int ret = 0;
    REP(i,len) {
        if (vv[s[i] - '0'] == 0) {
            vv[s[i] - '0'] = 1;
            ++ret;
        }
    }
    return ret;
}

class TheInteger {
public:
    long long find(long long n, int k) {
        string str = i2s(n);
        int len = str.length();
        
        if (len >= k) {
            if (getCount(str) == k) return n;
            
            RFOR(i,len-1,0) {
                string prefix = str.substr(0, i);
                FOR(j,str[i]-'0'+1,9) {
                    char digit = j + '0';

                    int cnt = getCount(prefix + digit);
                    
                    if (cnt > k) continue;
                    if (cnt + len - 1 - i < k) continue;

                    string other = "";
                    REP(ii,10) {
                        if (cnt == k) break;
                        if (vv[ii] == 1) continue;
                        vv[ii] = 1;
                        other += (char)(ii + '0');
                        ++cnt;
                    }

                    if (cnt < k) continue;

                    char least = 0;
                    REP(ii,10) {
                        if (vv[ii] == 1) {
                            least = ii + '0';
                            break;
                        }
                    }

                    while (other.length() < len - 1 - i) {
                        other += least;
                    }

                    sort(other.begin(), other.end());

                    return s2i(prefix + digit + other);
                }
            }
        }
        
        memset(vv, 0, sizeof(vv));
        string ret = "1";
        string other = "";
        vv[1] = 1;
        int cnt = 1;
        REP(i,10) {
            if (cnt == k) break;
            if (vv[i] == 1) continue;
            other += (char)(i + '0');
            ++cnt;
        }
        
        char ch = (k == 1 ? '1' : '0');
        while (other.length() < len) {
            other += ch;
        }
        
        sort(other.begin(), other.end());

        return s2i(ret + other);
    }
};
// BEGIN CUT HERE
int main() {
    {
        TheInteger theObject;
        eq(0, theObject.find(47L, 1),55LL);
    }
    {
        TheInteger theObject;
        eq(1, theObject.find(7L, 3),102LL);
    }
    {
        TheInteger theObject;
        eq(2, theObject.find(69L, 2),69LL);
    }
    {
        TheInteger theObject;
        eq(3, theObject.find(12364L, 3),12411LL);
    }
    return 0;
}
// END CUT HERE
