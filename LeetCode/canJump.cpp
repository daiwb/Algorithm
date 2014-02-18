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
    bool canJump(int A[], int n) {
        if (n <= 1) return true;
        int mx = A[0];
        FOR(i,0,n-1) {
            if (i > mx) break;
            mx = max(mx, i + A[i]);
        }
        return mx >= n - 1;
    }
};

int main() {
    Solution s;
    int A[] = {2, 3, 1, 1, 4};
    int B[] = {3, 2, 1, 0, 4};
    cout << s.canJump(A, 5) << endl;
    cout << s.canJump(B, 5) << endl;
    return 0;
}
