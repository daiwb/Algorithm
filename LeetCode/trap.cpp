class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        int lt = 0, rt = n - 1;
        int mxL = A[0], mxR = A[n - 1];
        int ret = 0;
        while (lt < rt) {
            if (mxL < mxR) {
                ++lt;
                mxL = max(mxL, A[lt]);
                ret += mxL - A[lt];
            } else {
                --rt;
                mxR = max(mxR, A[rt]);
                ret += mxR - A[rt];
            }
        }
        return ret;
    }
};
