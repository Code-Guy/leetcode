// 注意点：1. 矩阵的横纵为零的状态分别保存在行和列的起始位置，但是这样的话矩阵左上角就保存了两个状态，所以需要设置一个col0状态变量，保存第一列的状态
// 2.第二次遍历矩阵必须要倒序，因为如果正序的话，矩阵行列的状态会被提前改变，进而会产生不正确的结果

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        
        int col0 = 1; 
        
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j > 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};
