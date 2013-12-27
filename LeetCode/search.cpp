class Solution {
public:
    int search(int A[], int n, int target) {
        int lt = 0, rt = n - 1;
        while (lt <= rt) {
            int mt = (lt + rt) / 2;
            if (A[mt] == target) return mt;
            if (A[lt] <= A[mt]) {
                if (A[lt] <= target && target < A[mt]) rt = mt - 1;
                else lt = mt + 1;
            } else {
                if (A[mt] < target && target <= A[rt]) lt = mt + 1;
                else rt = mt - 1;
            }
        }
        return -1;
    }
};