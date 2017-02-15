// two pointers maintains max left and right height, accumulate water bin by bin
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int maxLeft= 0, maxRight = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] > maxLeft) maxLeft = height[left];
                else water += maxLeft - height[left];
                left++;
            }
            else {
                if (height[right] > maxRight) maxRight = height[right];
                else water += maxRight - height[right];
                right--;
            }
        }
        return water;
    }
};
