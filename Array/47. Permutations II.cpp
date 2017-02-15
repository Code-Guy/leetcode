// use value not reference
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        permute(nums, 0, permutations);
        return permutations;
    }
    
private:
    void permute(vector<int> nums, int begin, vector<vector<int>> &permutations) {
        if (begin == nums.size() - 1) {
            permutations.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            if (i != begin && nums[i] == nums[begin]) continue;
            swap(nums[i], nums[begin]);
            permute(nums, begin + 1, permutations);
        }
    }
};
