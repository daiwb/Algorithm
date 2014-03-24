#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int n = matrix.size();
        if (n == 0) return res;
        int m = matrix[0].size();
        if (m == 0) return res;
        vector<vector<bool> > flag(n, vector<bool>(m, false));
        int x = 0, y = 0;
        int idx = 0;
        while (true) {
            res.push_back(matrix[x][y]);
            flag[x][y] = true;
            bool isok = false;
            REP(i,2) {
                int tx = x + dir[(i + idx) % 4][0];
                int ty = y + dir[(i + idx) % 4][1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (flag[tx][ty]) continue;
                x = tx, y = ty;
                flag[tx][ty] = true;
                idx = (i + idx) % 4;
                isok = true;
                break;
            }
            if (!isok) break;
        }
        return res;
    }
};

int main() {
    int data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int> > input(3);
    REP(i,3) REP(j,3) input[i].push_back(data[i][j]);
    Solution s;
    vector<int> ret = s.spiralOrder(input);
    REP(i,ret.size()) cout << ret[i] << " ";
    cout << endl;
    return 0;
}
