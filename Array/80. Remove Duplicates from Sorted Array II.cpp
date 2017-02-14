class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        for (int num : nums) {
            if (p < 2 || num > nums[p - 2]) {
                nums[p++] = num;
            }
        }
        return p;
    }
};
