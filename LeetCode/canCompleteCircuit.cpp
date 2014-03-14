class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int res = -1;
        int sum = 0, total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                res = i;
                sum = 0;
            }
        }
        if (total < 0) return -1;
        else return res + 1;
    }
};