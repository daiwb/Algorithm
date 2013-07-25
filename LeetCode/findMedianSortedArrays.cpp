#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid = (m + n - 1) / 2;
        int st = 0, ed = m - 1, i = 0, j = 0;
        while (st <= ed) {
            i = (st + ed) / 2;
            j = mid - i;

            int b1 = getVal(B, n, j - 1), b2 = getVal(B, n, j);
            if (A[i] >= b1 && A[i] <= b2) {
                break;
            } else if (A[i] < b1) {
                st = i + 1;
            } else if (A[i] > b2) {
                ed = i - 1;
            }
        }

        if (st <= ed) {
            if ((m + n) & 1) {
                return A[i];
            } else {
                int o = min(getVal(A, m, i + 1), getVal(B, n, j));
                return (A[i] + o) * 0.5;
            }
        } else {
            return findMedianSortedArrays(B, n, A, m);
        }
    }

    int getVal(int a[], int n, int idx) {
        if (idx < 0) return INT_MIN;
        else if (idx >= n) return INT_MAX;
        else return a[idx];
    }
};
