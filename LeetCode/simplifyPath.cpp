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

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

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

class Solution {
public:
    string simplifyPath(string path) {
        VS a = split(path, string("/"));
        VS mm;
        REP(i,a.size()) {
            if (a[i] == ".") {
            } else if (a[i] == "..") {
                if (!mm.empty()) mm.pop_back();
            } else {
                mm.push_back(a[i]);
            }
        }
        if (mm.empty()) return "/";
        string res = "";
        REP(i,mm.size()) res += "/" + mm[i];
        return res;
    }
};

int main() {
    Solution s = Solution();
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << s.simplifyPath("/...") << endl;
    cout << s.simplifyPath("/.") << endl;
    cout << s.simplifyPath("/..") << endl;
    return 0;
}
