class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int begin = 0, end = height.size() - 1;
        while (begin < end) {
            int h = min(height[begin], height[end]);
            water = max(water, (end - begin) * h);
            while (begin < end && height[begin] <= h) begin++;
            while (begin < end && height[end] <= h) end--;
        }
        return water;
    }
};
