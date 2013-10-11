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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        int n = num.size();
        REP(i,n) {
            if (i != 0 && num[i] == num[i - 1]) continue;
            FOR(j,i+1,n-1) {
                if (j != i + 1 && num[j] == num[j - 1]) continue;
                int s = num[i] + num[j];
                int lt = j + 1;
                int rt = n - 1;
                while (lt < rt) {
                    if (num[lt] + num[rt] + s == target) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[lt]);
                        tmp.push_back(num[rt]);
                        ret.push_back(tmp);
                        ++lt;
                        --rt;
                    } else if (num[lt] + num[rt] + s < target) {
                        ++lt;
                    } else {
                        --rt;
                    }
                }
            }
        }
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};

int main() {
    Solution s = Solution();
    int data[] = {1, 0, -1, 0, -2, 2};
    vector<int> mm;
    int sz = sizeof(data) / sizeof(int);
    REP(i,sz) mm.push_back(data[i]);
    vector<vector<int> > ret = s.fourSum(mm, 0);
    REP(i,ret.size()) {
        REP(j,ret[i].size()) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
