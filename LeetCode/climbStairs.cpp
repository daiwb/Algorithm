class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> mm(n + 1);
        mm[1] = 1;
        mm[2] = 2;
        for (int i = 3; i <= n; ++i) {
            mm[i] = mm[i - 1] + mm[i - 2];
        }
        return mm[n];
    }
};
