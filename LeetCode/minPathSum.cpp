class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > mm(m, vector<int>(n));
        mm[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i) mm[0][i] = mm[0][i - 1] + grid[0][i];
        for (int i = 1; i < m; ++i) mm[i][0] = mm[i - 1][0] + grid[i][0];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                mm[i][j] = min(mm[i - 1][j], mm[i][j - 1]) + grid[i][j];
            }
        }
        return mm[m - 1][n - 1];
    }
};