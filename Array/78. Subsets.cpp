// get kth bit of a binary number: (i >> k) & 1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ss;
        int n = nums.size();
        int sn = pow(2, n);
        for (int i = 0; i < sn; i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subset.push_back(nums[j]);
                }
            }
            ss.push_back(subset);
        }
        return ss;
    }
};
