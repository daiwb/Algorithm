class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int idx = m + n - 1;
        int ia = m - 1, ib = n - 1;
        while (idx >= 0) {
            if (ia < 0) {
                while (idx >= 0) A[idx--] = B[ib--];
            }
            else if (ib < 0) {
                while (idx >= 0) A[idx--] = A[ia--];
            }
            else if (A[ia] > B[ib]) A[idx--] = A[ia--];
            else A[idx--] = B[ib--];
        }
    }
};