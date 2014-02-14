#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int idx = n - 1;
        while (idx - 1 >= 0 && num[idx - 1] >= num[idx]) --idx;
        if (--idx <= -1) {
            reverse(num.begin(), num.end());
            return;
        }

        int lt = idx + 1, rt = n - 1;
        while (lt <= rt) {
            int mt = (lt + rt) / 2;
            if (num[mt] <= num[idx]) {
                rt = mt - 1;
            } else {
                lt = mt + 1;
            }
        }

        swap(num[idx], num[rt]);
        reverse(num.begin() + idx + 1, num.end());
    }
};

void test(int mm[], int len) {
    vector<int> num;
    num.assign(mm, mm + len);
    Solution s;
    s.nextPermutation(num);
    REP(i,num.size()) cout << num[i] << " ";
    cout << endl;
}

int main() {
    int mm1[3] = {1, 2, 3};
    test(mm1, sizeof(mm1) / sizeof(mm1[0]));

    int mm2[] = {3, 2, 1};
    test(mm2, sizeof(mm2) / sizeof(mm2[0]));

    int mm3[] = {1, 1, 5};
    test(mm3, sizeof(mm3) / sizeof(mm3[0]));
    
    return 0;
}
