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

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if (n < 2) return 0;
        int mi = num[0], ma = num[0];
        FOR(i,1,n-1) {
            mi = min(mi, num[i]);
            ma = max(ma, num[i]);
        }
        if (mi == ma) return 0;
        int dis = ceil((ma - mi) * 1.0 / (n - 1));
        int sz = (ma - mi) / dis + 1;
        vector<int> bmi(sz, -1), bma(sz, -1);
        REP(i,n) {
            int idx = (int)((num[i] - mi) / dis);
            if (bmi[idx] == -1 || num[i] < bmi[idx]) bmi[idx] = num[i];
            if (bma[idx] == -1 || num[i] > bma[idx]) bma[idx] = num[i];
        }
        vector<pair<int, int> > mm;
        REP(i,sz) {
            if (bmi[i] == -1) continue;
            mm.push_back(make_pair(bmi[i], bma[i]));
        }
        int res = 0;
        REP(i,mm.size()-1) {
            res = max(res, mm[i + 1].first - mm[i].second);
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
