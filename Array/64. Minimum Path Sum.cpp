// Solution 1 modify the input O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int top = i == 0 ? INT_MAX : grid[i - 1][j];
                int left = j == 0 ? INT_MAX : grid[i][j - 1];
                grid[i][j] += min(top, left);
            }
        }
        return grid[m - 1][n - 1];
    }
};

// Solution 2 don't modify the input O(N^2)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> s(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++) {
            s[i][0] = s[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            s[0][j] = s[0][j - 1] + grid[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                s[i][j] = min(s[i - 1][j], s[i][j - 1]) + grid[i][j];
            }
        }
        return s[m - 1][n - 1];
    }
};

// Solution 3 don't modify the input O(2*N)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);

        for (int i = 1; i < m; i++) {
            pre[i] = pre[i - 1] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            cur[0] = pre[0] + grid[0][j];
            for (int i = 1; i < m; i++) {
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            }
            pre = cur;
        }
        return pre[m - 1];
    }
};

// Solution 4 don't modify the input O(N)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> cur(m, grid[0][0]);

        for (int i = 1; i < m; i++) {
            cur[i] = cur[i - 1] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++) {
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
            }
        }
        return cur[m - 1];
    }
};

