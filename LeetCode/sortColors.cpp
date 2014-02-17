#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    void sortColors(int A[], int n) {
        if (n <= 1) return;

        int lt = 0, rt = n - 1;
        while (A[lt] == 0) ++lt;
        while (A[rt] == 2) --rt;
        FOR(i,lt,rt) {
            if (A[i] == 0) swap(A[lt++], A[i]);
            if (A[i] == 2) swap(A[rt--], A[i--]);
        }
    }
};

int main() {
    int A[] = {2, 1, 0, 2, 0, 1, 1, 1, 0, 2, 2, 0, 2, 1, 0};
    Solution s;
    s.sortColors(A, 15);
    REP(i,15) cout << A[i] << endl;
    return 0;
}
