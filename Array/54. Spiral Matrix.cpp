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
