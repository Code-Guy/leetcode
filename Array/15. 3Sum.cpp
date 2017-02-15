// O(N^2) two pointers skip duplicates
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        int n = nums.size();
        if (n < 3) return triplets;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2;) {
            int num = nums[i];
            int target = -num;
            int begin = i + 1, end = n - 1;
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
