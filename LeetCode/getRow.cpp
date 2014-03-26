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
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        FOR(i,1,rowIndex) {
            vector<int> t(rowIndex + 1);
            t[0] = res[0];
            t[i] = res[i - 1];
            FOR(j,1,i-1) t[j] = res[j - 1] + res[j];
            res = t;
        }
        return res;
    }
};

int main() {
    Solution s;
    REP(i,6) {
        vector<int> res = s.getRow(i);
        REP(j,res.size()) cout << res[j] << " ";
        cout << endl;
    }
    return 0;
}
