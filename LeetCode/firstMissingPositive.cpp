#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        REP(i,n) {
            if (A[i] <= 0 || A[i] > n) continue;
            if (A[i] == i + 1) continue;
            if (A[A[i] - 1] == A[i]) continue;
            swap(A[A[i] - 1], A[i]);
            --i;
        }
        REP(i,n) {
            if (A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

int main() {
    int data[] = {3,4,1,2,6};
    Solution s;
    cout << s.firstMissingPositive(data, 5) << endl;
    return 0;
}
