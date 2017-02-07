// use a sliding window O(nk)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        // for integrity
        //if (k <= 0) return false;
        //else if (k >= nums.size()) k = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            else {
                s.insert(nums[i]);
            }
        }
        
        return false;
    }
};
