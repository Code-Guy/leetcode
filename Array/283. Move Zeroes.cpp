// Solution 1 swap left zero with right non-zero
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int j = i + 1;
                while (true) {
                    if (j >= nums.size()) {
                        return;
                    }
                    
                    if (nums[j] != 0) {
                        break;
                    }
                    j++;
                }
                swap(nums[i], nums[j]);
            }
        }
    }
};

// solution 2 move non-zero to the left, and fill the right with zero
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
