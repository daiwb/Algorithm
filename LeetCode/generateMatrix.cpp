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
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        int x = 0, y = -1;
        int idx = 0;
        FOR(i,1,n*n) {
            int tx = x + dir[idx][0], ty = y + dir[idx][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n || res[tx][ty] != 0) idx = (idx + 1) % 4;
            x += dir[idx][0], y += dir[idx][1];
            res[x][y] = i;
        }
        return res;
    }
};

int main() {
    return 0;
}
