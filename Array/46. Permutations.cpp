// Solution 1 backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> permutation;
        permute(nums, permutations, permutation);
        return permutations;
    }
    
private:
    void permute(const vector<int>& nums,
        vector<vector<int>> &permutations, vector<int> &permutation) {
        if (permutation.size() == nums.size()) {
            permutations.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (find(permutation.begin(), permutation.end(), nums[i]) == permutation.end()) { // can this check statement be avoided?
                permutation.push_back(nums[i]);
                permute(nums, permutations, permutation);
                permutation.pop_back();
            }
        }
    }
};

// Solution 2 swap in place
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        permute(nums, 0, permutations);
        return permutations;
    }
    
private:
    void permute(vector<int>& nums, int begin, vector<vector<int>> &permutations) {
        if (begin == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[i], nums[begin]);
            permute(nums, begin + 1, permutations);
            swap(nums[i], nums[begin]);
        }
    }
};
