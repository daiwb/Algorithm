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
    string s;
    int len;
    vector<int> mm;
    vector<vector<int> > vv;
    bool isok(int st, int ed) {
        return vv[st][ed] == 1;
    }
    int doit(int idx) {
        int& res = mm[idx];
        if (res != -1) return res;
        if (idx >= len) return res = 0;
        if (isok(idx, len - 1)) return res = 0;
        res = 1 + doit(idx + 1);
        for (int i = idx + 1; i < len; ++i) {
            if (!isok(idx, i)) continue;
            res = min(res, 1 + doit(i + 1));
        }
        return res;
    }
    int minCut(string _s) {
        s = _s;
        len = s.length();
        if (len <= 1) return 0;
        vv.assign(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i) vv[i][i] = 1;
        for (int i = 0; i < len - 1; ++i) vv[i][i + 1] = (s[i] == s[i + 1]);
        for (int sz = 2; sz < len; ++sz) {
            for (int i = 0; i < len - sz; ++i) {
                if (s[i] == s[i + sz] && vv[i + 1][i + sz - 1] == 1) vv[i][i + sz] = 1;
            }
        }
        mm.assign(len + 5, -1);
        return doit(0);
    }
};

int main() {
    Solution s = Solution();
    cout << s.minCut("dde") << endl;
    return 0;
}
