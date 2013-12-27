class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ret = A[0], t = A[0];
        for (int i = 1; i < n; ++i) {
            t = max(0, t) + A[i];
            ret = max(ret, t);
        }
        return ret;
    }
};
