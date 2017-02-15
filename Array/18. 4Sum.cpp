class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        int n = nums.size();
        if (n < 4) return quadruplets;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ) {
            int num = nums[i];
            vector<vector<int>> triplets = threeSum(nums, i + 1, target - num);
            for (int j = 0; j < triplets.size(); j++) {
                quadruplets.push_back(vector<int>{num});
                quadruplets.back().insert(quadruplets.back().end(), triplets[j].begin(), triplets[j].end());
            }
            while (nums[++i] == num);
        }
        return quadruplets;
    }
    
private:
    vector<vector<int>> threeSum(const vector<int>& nums, int start, int target) {
        vector<vector<int>> triplets;
        for (int i = start; i < nums.size() - 2;) {
            int num = nums[i];
            int goal = target - num;
            int begin = i + 1, end = nums.size() - 1;
            while (begin < end) {
                int lhs = nums[begin], rhs = nums[end];
                int sum = lhs + rhs;
                if (sum < goal) begin++;
                else if (sum > goal) end--;
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
