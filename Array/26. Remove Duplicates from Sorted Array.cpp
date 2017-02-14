// Solution 1 using stl unique
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};

// Solution 2 pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int p = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                int ap = p++;
                if (ap != i) { // 避免不必要的拷贝
                    nums[ap] = nums[i];
                }
            }
        }
        return p;
    }
};
