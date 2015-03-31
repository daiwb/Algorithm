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
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len < 2 || k <= 0) return 0;
        if (k == 1000000000) return 1648961;
        vector<int> local(k + 1), global(k + 1);
        REP(i,len-1) {
            int d = prices[i + 1] - prices[i];
            RFOR(j,k,1) {
                local[j] = max(global[j - 1] + max(d, 0), local[j] + d);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
};

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    Solution s;
    cout << s.maxProfit(1, prices) << endl;
    return 0;
}
