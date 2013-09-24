#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    int maxArea(vector<int> &height) {
        int ret = 0;
        int lt = 0, rt = height.size() - 1;
        while (lt < rt) {
            ret = max(ret, (rt - lt) * min(height[lt], height[rt]));
            if (height[lt] < height[rt]) ++lt;
            else --rt;
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> mm;
    mm.push_back(3);
    mm.push_back(2);
    mm.push_back(1);
    mm.push_back(3);
    cout << s.maxArea(mm) << endl;

    mm.clear();
    // 10,14,10,4,10,2,6,1,6,12
    mm.push_back(10);
    mm.push_back(14);
    mm.push_back(10);
    mm.push_back(4);
    mm.push_back(10);
    mm.push_back(2);
    mm.push_back(6);
    mm.push_back(1);
    mm.push_back(6);
    mm.push_back(12);
    cout << s.maxArea(mm) << endl;
    return 0;
}
