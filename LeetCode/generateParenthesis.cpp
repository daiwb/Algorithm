#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > mm(n + 1, vector<string>());
        mm[0].push_back("");
        if (n == 0) return mm[0];
        mm[1].push_back("()");
        FOR(i,2,n) {
            for (int j = 1; j < (i << 1); j += 2) {
                int m1 = (j - 1) >> 1, m2 = ((i << 1) - 1 - j) >> 1;
                REP(i1,mm[m1].size()) {
                    REP(i2,mm[m2].size()) {
                        mm[i].push_back("(" + mm[m1][i1] + ")" + mm[m2][i2]);
                    }
                }
            }
        }
        sort(mm[n].begin(), mm[n].end());
        return mm[n];
    }
};

int main() {
    Solution s = Solution();
    vector<string> vs = s.generateParenthesis(3);
    REP(i,vs.size()) {
        cout << vs[i] << endl;
    }
    return 0;
}
