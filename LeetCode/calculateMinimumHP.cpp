#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        vector<vector<int> > mm(m, vector<int>(n));

        mm[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
        RFOR(i,m-2,0) mm[i][n - 1] = max(1, mm[i + 1][n - 1] - dungeon[i][n - 1]);
        RFOR(j,n-2,0) mm[m - 1][j] = max(1, mm[m - 1][j + 1] - dungeon[m - 1][j]);
        RFOR(i,m-2,0) {
            RFOR(j,n-2,0) {
                mm[i][j] = max(1, min(mm[i + 1][j], mm[i][j + 1]) - dungeon[i][j]);
            }
        }
        return mm[0][0];
    }
};

int main() {
    vector<vector<int> > d(3, vector<int>());
    d[0].push_back(-2);
    d[0].push_back(-3);
    d[0].push_back(3);
    d[1].push_back(-5);
    d[1].push_back(-10);
    d[1].push_back(1);
    d[2].push_back(10);
    d[2].push_back(30);
    d[2].push_back(-5);
    Solution s;
    cout << s.calculateMinimumHP(d) << endl;
    return 0;
}
