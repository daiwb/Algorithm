#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

vector<VI> mm;
int n, m;
string s, t;

int dp(int i1, int i2) {
    int& res = mm[i1][i2];
    if (res != -1) return res;

    if (i2 == m) return res = 1;
    if (i1 == n) return res = 0;

    res = 0;
    FOR(i,i1,n-1) {
        if (s[i] == t[i2]) res += dp(i + 1, i2 + 1);
    }

    return res;    
}

class Solution {
public:
    int numDistinct(string S, string T) {
        n = S.length(), m = T.length();
        s = S, t = T;
        if (m > n) return 0;
        if (m == n) return S == T ? 1 : 0;
        mm.assign(n + 5, VI(m + 5, -1));
        return dp(0, 0);
    }
};

int main() {
    Solution sol;
    cout << sol.numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
