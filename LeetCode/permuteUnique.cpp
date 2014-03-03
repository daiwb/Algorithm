#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        do {
            res.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return res;
    }
};

int main() {
    vector<int> mm;
    mm.push_back(1);
    mm.push_back(2);
    mm.push_back(1);
    Solution s;
    vector<vector<int> > res = s.permuteUnique(mm);
    REP(i,res.size()) {
        REP(j,res[i].size()) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
