#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int ret = 0;
        int mm = prices[0];
        FOR(i,1,prices.size()-1) {
            ret = max(ret, prices[i] - mm);
            mm = min(mm, prices[i]);
        }
        return ret;
    }
};
