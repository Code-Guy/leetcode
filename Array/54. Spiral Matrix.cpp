// Solution 1 naive traverse
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int r = 0, c = 0;
        int m = matrix.size();
        if (m == 0) return ret;
        int n = matrix[0].size();
        if (n == 0) return ret;
        
        while (true) {
            for (int i = 0; i < n; i++, c++) {
                ret.push_back(matrix[r][c]);
            }
            r++; c--;
            if (--m == 0) break;
            for (int i = 0; i < m; i++, r++) {
                ret.push_back(matrix[r][c]);
            }
            r--; c--;
            if (--n == 0) break;
            for (int i = 0; i < n; i++, c--) {
                ret.push_back(matrix[r][c]);
            }
            r--; c++;
            if (--m == 0) break;
            for (int i = 0; i < m; i++, r--) {
                ret.push_back(matrix[r][c]);
            }
            r++; c++;
            if (--n == 0) break;
        }
        return ret;
    }
};

// Solution 2 traverse with direction, reduce four loops to one
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0) return ret;
        int n = matrix[0].size();
        if (n == 0) return ret;
        
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int step[2] = {n, m - 1};
        int r = 0, c = -1;
        int d = 0;
        while (step[d % 2]) {
            for (int i = 0; i < step[d % 2]; i++) {
                r += dir[d][0]; 
                c += dir[d][1];
                ret.push_back(matrix[r][c]);
            }
            step[d % 2]--;
            d = (d + 1) % 4;
        }
        return ret;
    }
};
