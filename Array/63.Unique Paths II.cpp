class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> s(m, 0);
        s[0] = 1;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (obstacleGrid[i][j] == 1) {
                    s[i] = 0;
                }
                else if (i > 0) {
                    s[i] += s[i - 1];
                }
            }
        }
        return s[m - 1];
    }
};
