// O(N^2) two pointers skip duplicates
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            int num = nums[i];
            int target = -num;
            int begin = i + 1, end = nums.size() - 1;
            while (begin < end) {
                int lhs = nums[begin], rhs = nums[end];
                int sum = lhs + rhs;
                if (sum < target) begin++;
                else if (sum > target) end--;
                else {
                    triplets.push_back(vector<int>{ num, lhs, rhs });
                    while (nums[++begin] == lhs);
                    while (nums[--end] == rhs);
                }
            }
            while (nums[++i] == num);
        }
        return triplets;
    }
};
