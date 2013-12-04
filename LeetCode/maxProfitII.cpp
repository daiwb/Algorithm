class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i) {
            ret += max(0, prices[i] - prices[i - 1]);
        }
        return ret;
    }
};