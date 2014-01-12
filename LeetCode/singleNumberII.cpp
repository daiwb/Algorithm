class Solution {
public:
    int singleNumber(int A[], int n) {
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            int ta = a ^ A[i] & ~b;
            int tb = b ^ A[i] & (a | b);
            a = ta;
            b = tb;
        }
        return a;
    }
};
