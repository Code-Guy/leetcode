// if h[k + 1] <= h[k], then k+1 isn't the Largest Rectangle's right bound
// 1. Traverse the pruning O(N^2)
// 2. DP O(n)
// 3. Two stacks
// 4. One stack
class Solution {
public:
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
