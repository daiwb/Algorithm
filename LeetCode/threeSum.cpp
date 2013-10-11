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
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        int n = num.size();
        REP(i,n) {
            if (i != 0 && num[i] == num[i - 1]) continue;
            int lt = i + 1;
            int rt = n - 1;
            while (lt < rt) {
                if (num[lt] + num[rt] == -num[i]) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[lt]);
                    tmp.push_back(num[rt]);
                    ret.push_back(tmp);
                    ++lt;
                    --rt;
                } else if (num[lt] + num[rt] < -num[i]) {
                    ++lt;
                } else {
                    --rt;
                }
            }
        }
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};

int main() {
    Solution s = Solution();
    int data[] = {2,-8,8,6,-14,-12,11,-10,13,14,7,3,10,-13,3,-15,7,3,-11,-8,4,5,9,11,7,1,3,13,14,-13,3,-6,-6,-12,-15,-12,-9,3,-15,-11,-6,-1,0,11,2,-12,3,-6,6,0,-6,-12,-10,-12,6,5,-4,-5,-5,-4,-11,13,5,-2,-13,-3,-7,-15,8,-15,12,-13,0,-3,6,9,-8,-6,10,5,9,-11,0,7,-15,-8,-3,-4,-6,7,7,-2,-2,-11,3,0,-6,12,0,-13,4,-3,11,-11,1,2,13,8,4,9,-1,-2,5,14,12,5,13,-6,-13,-8,9,1,5,-8,-2,-6,-1};
    vector<int> mm;
    int sz = sizeof(data) / sizeof(int);
    REP(i,sz) mm.push_back(data[i]);
    vector<vector<int> > ret = s.threeSum(mm);
    REP(i,ret.size()) {
        REP(j,ret[i].size()) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
