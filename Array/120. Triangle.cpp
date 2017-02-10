// Solution 1 O(1) space O(N^2) time, but has to modify the input triangle
// state transition function: S[i][j] += min(S[i + 1][j], S[i + 1][j + 1])
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int r = triangle.size() - 2; r >= 0; r--) {
            for (int c = 0; c < triangle[r].size(); c++) {
                triangle[r][c] += min(triangle[r+1][c], triangle[r+1][c+1]);
            }
        }
        return triangle[0][0];
    }
};

// Solution 2 O(N) space O(N^2) time, decrease the state dimensions to one
// state transition function: S[i][j] = min(S[i + 1][j], S[i + 1][j + 1]) + triangle[i][j]
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> s(triangle.back());
        for (int r = triangle.size() - 2; r >= 0; r--) {
            for (int c = 0; c <= r; c++) {
                s[c] = min(s[c], s[c+1]) + triangle[r][c];
            }
        }
        return s[0];
    }
};
