class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        if (n <= 0) return ret;
        
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int step[2] = {n, n - 1};
        int r = 0, c = -1;
        int d = 0, k = 0;
        while (step[d % 2]) {
            for (int i = 0; i < step[d % 2]; i++) {
                r += dir[d][0]; 
                c += dir[d][1];
                ret[r][c] = ++k;
            }
            step[d % 2]--;
            d = (d + 1) % 4;
        }
        return ret;
    }
};
