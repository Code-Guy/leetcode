// 维护smaller和bigger两个变量，遇到负数是两者交换
// bigger是当前元素与bigger和当前元素乘积的最大值，smaller是当前元素与smaller和当前元素乘积的最小值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums.front();
        for (int i = 1, bigger = maxp, smaller = maxp; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(bigger, smaller);
            }
            
            bigger = max(nums[i], bigger * nums[i]);
            smaller = min(nums[i], smaller * nums[i]);
            maxp = max(maxp, bigger);
        }
        return maxp;
    }
};
