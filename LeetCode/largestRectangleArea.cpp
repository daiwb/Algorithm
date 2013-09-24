#include <iostream>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int n = height.size();
        int ret = 0, i = 0;
        vector<int> que;
        while (i < n) {
            if (que.empty() || height[que.back()] <= height[i]) {
                que.push_back(i++);
            } else {
                while (!que.empty() && height[que.back()] >= height[i]) {
                    int tp = que.back();
                    que.pop_back();
                    int wid = que.empty() ? i : i - 1 - que.back();
                    ret = max(ret, height[tp] * wid);
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> mm;
    mm.push_back(2);
    mm.push_back(1);
    mm.push_back(5);
    mm.push_back(6);
    mm.push_back(2);
    mm.push_back(3);
    cout << s.largestRectangleArea(mm) << endl;
    return 0;
}
