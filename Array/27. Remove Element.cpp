// Solution 1 two pointers swap
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) return 0;
        int begin = -1, end = n;
        while (true) {
            while (++begin < n && nums[begin] != val);
            while (--end >= 0 && nums[end] == val);
            if (begin >= end) break;
            swap(nums[begin], nums[end]);
        }
        nums.erase(nums.begin() + begin, nums.end());
        return begin;
    }
};

// Solution 2 overwrite sequentially
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        for (int num : nums) {
            if (num != val) {
                nums[p++] = num;
            }
        }
        return p;
    }
};
