// Solution 1 using the largestRectangleArea method 
// 把第0行到第i行形成的矩形看成最大直方图矩形问题的输入
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = 0;
        vector<int> heights(matrix.front().size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    
private:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        heights.push_back(0);
        vector<int> indices;
        for (int i = 0; i < heights.size(); i++) {
            while (!indices.empty() && heights[i] <= heights[indices.back()]) {
                int h = heights[indices.back()];
                indices.pop_back();
                int w = indices.empty() ? i : i - indices.back() - 1;
                maxArea = max(maxArea, h * w);
            }
            indices.push_back(i);
        }
        return maxArea;
    }
};

// Solution 2 DP 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int maxArea = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for (int i = 0; i < m; i++) {
            int cl = 0, cr = n;
            for (int j = 0; j < n; j++) {
                int lj = j;
                int rj = n - j - 1;
                
                if (matrix[i][lj] == '1') {
                    height[lj]++;
                    left[lj] = max(left[lj], cl);
                }
                else {
                    height[lj] = 0;
                    left[lj] = 0;
                    cl = lj + 1;
                }
                
                if (matrix[i][rj] == '1') {
                    right[rj] = min(right[rj], cr);
                }
                else {
                    right[rj] = n;
                    cr = rj;
                }
            }
            
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            }
        }
        return maxArea;
    }
};
