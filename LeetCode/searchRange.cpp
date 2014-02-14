#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (target <= A[m]) r = m - 1;
            else l = m + 1;
        }
        if (n == 0 || r + 1 >= n || A[r + 1] != target) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        ret.push_back(r + 1);

        l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (target >= A[m]) l = m + 1;
            else r = m - 1;
        }
        ret.push_back(l - 1);
        return ret;
    }
};

void test(int mm[], int len, int target) {
    Solution s;
    vector<int> ret = s.searchRange(mm, len, target);
    cout << ret[0] << " " << ret[1] << endl;
}

int main() {
    int mm1[] = {5, 7, 7, 8, 8, 10};
    test(mm1, sizeof(mm1) / sizeof(mm1[0]), 8);
    test(mm1, sizeof(mm1) / sizeof(mm1[0]), 4);
    test(mm1, sizeof(mm1) / sizeof(mm1[0]), 11);
    test(mm1, sizeof(mm1) / sizeof(mm1[0]), 6);

    int mm2[] = {};
    test(mm2, sizeof(mm2) / sizeof(mm2[0]), 8);

    return 0;
}
