class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int mm[105][105];
        for (int i = 0; i < n; ++i) {
            mm[0][i] = 1;
            if (obstacleGrid[0][i] == 1) mm[0][i] = 0;
            if (i > 0 && mm[0][i - 1] == 0) mm[0][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            mm[i][0] = 1;
            if (obstacleGrid[i][0] == 1) mm[i][0] = 0;
            if (i > 0 && mm[i - 1][0] == 0) mm[i][0] = 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) mm[i][j] = 0;
                else {
                    mm[i][j] = mm[i - 1][j] + mm[i][j - 1];
                }
            }
        }
        return mm[m - 1][n - 1];
    }
};