#include <iostream>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> mm1(n, 0), mm2(n, 0);
        
        int mi = prices[0];
        FOR(i,1,n-1) {
            mm1[i] = max(mm1[i - 1], prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        
        int mx = prices[n - 1];
        RFOR(i,n-2,0) {
            mm2[i] = max(mm2[i + 1], mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        
        int ret = mm1[n - 1];
        FOR(i,0,n-2) {
            ret = max(ret, mm1[i] + mm2[i + 1]);
        }
        return ret;
    }
};

int main() {
    return 0;
}
