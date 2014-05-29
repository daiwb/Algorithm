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

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        string ss = string(s);
        string pp = string(p);
        int ls = ss.length(), lp = pp.length();
        int i1 = 0, i2 = 0;
        int star = -1, ts;
        while (i1 < ls) {
            if (i2 < lp) {
                if (ss[i1] == pp[i2] || pp[i2] == '?') {
                    ++i1;
                    ++i2;
                    continue;
                }
            
                if (pp[i2] == '*') {
                    star = i2++;
                    ts = i1;
                    continue;
                }
            }
            
            if (star != -1) {
                i2 = star + 1;
                i1 = ++ts;
                continue;
            }

            return false;
        }

        while (i2 < lp && pp[i2] == '*') ++i2;
        return i2 == lp;
    }
};

int main() {
    Solution s = Solution();
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", "?*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    return 0;
}
