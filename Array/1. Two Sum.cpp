// online O(n) algorithm
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = umap.find(target - nums[i]);
            if (iter == umap.end()) {
                umap[nums[i]] = i;
            }
            else {
                ret.push_back(i);
                ret.push_back(umap[target - nums[i]]);
            }
        }
        return ret;
    }
};
