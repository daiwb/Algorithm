class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int last = A[0] - 1, cnt = 0, idx = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == last) {
                if (++cnt <= 2) A[idx++] = A[i];
            } else {
                last = A[i];
                cnt = 1;
                A[idx++] = A[i];
            }
        }
        return idx;
    }
};