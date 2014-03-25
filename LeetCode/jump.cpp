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
    int jump(int A[], int n) {
        int ret = 0;
        int cur = 0, next = 0;
        REP(i,n) {
            if (i > cur) {
                cur = next;
                if (next < i) return -1;
                ++ret;
            }
            next = max(next, i + A[i]);
        }
        return ret;
    }
};

int main() {
    int A[] = {2,3,1,1,4};
    int B[] = {2,0,0,0,0};
    Solution s;
    cout << s.jump(B, 5) << endl;
    return 0;
}
