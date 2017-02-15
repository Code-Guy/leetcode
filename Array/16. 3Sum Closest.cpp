class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            int begin = i + 1, end = nums.size() - 1;
            int sum = 0;
            while (begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if (abs(sum - target) < abs(closest)) closest = sum - target;
                if (sum < target) begin++;
                else if (sum > target) end--;
                else return target;
            }
        }
        return closest + target;
    }
};
