#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int ret = num[0] + num[1] + num[2];
        int d = abs(ret - target);
        int n = num.size();
        REP(i,n) {
            if (i != 0 && num[i] == num[i - 1]) continue;
            int lt = i + 1;
            int rt = n - 1;
            while (lt < rt) {
                int s = num[i] + num[lt] + num[rt];
                if (s == target) {
                    return s;
                } else {
                    if (abs(s - target) < d) {
                        ret = s;
                        d = abs(s - target);
                    }
                    if (s < target) ++lt;
                    else --rt;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    int data[] = {-1, 2, 1, -4};
    vector<int> mm;
    int sz = sizeof(data) / sizeof(int);
    REP(i,sz) mm.push_back(data[i]);
    int ret = s.threeSumClosest(mm, 1);
    cout << ret << endl;
    return 0;
}
