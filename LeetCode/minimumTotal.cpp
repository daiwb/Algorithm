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
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        if (n == 1) return triangle[0][0];
        vector<int> mm(n);
        mm[0] = triangle[0][0];
        FOR(i,2,n) {
            vector<int> tp(n);
            tp[0] = mm[0] + triangle[i - 1][0];
            tp[i - 1] = mm[i - 2] + triangle[i - 1][i - 1];
            FOR(j,1,i-2) tp[j] = min(mm[j - 1], mm[j]) + triangle[i - 1][j];
            mm = tp;
        }
        int res = mm[0];
        FOR(i,1,n-1) res = min(res, mm[i]);
        return res;
    }
};

int main() {
    int data[4][4] = {{2},{3,4},{6,5,7},{4,1,8,3}};
    vector<vector<int> > input(4);
    REP(i,4) {
        REP(j,i+1) input[i].push_back(data[i][j]);
    }
    Solution s;
    cout << s.minimumTotal(input) << endl;
    return 0;
}
