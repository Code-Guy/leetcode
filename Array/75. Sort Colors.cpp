// Solution 1 counting sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redCnt = 0, whiteCnt = 0, blueCnt = 0;
        for (int num : nums) {
            switch (num) {
                case 0:
                    redCnt++;
                break;
                case 1:
                    whiteCnt++;
                break;
                case 2:
                    blueCnt++;
                break;
            }
        }
        for (int &num : nums) {
            if (redCnt-- > 0) num = 0;
            else if (whiteCnt-- > 0) num = 1;
            else if (blueCnt-- > 0) num = 2;
        }
    }
};

// Solution 2 swap 2 to tail, swap 0 to head, the 1 is in the middle
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        for (int i = 0; i <= two; i++) {
            while (nums[i] == 2 && i < two) swap(nums[i], nums[two--]);
            while (nums[i] == 0 && i > zero) swap(nums[i], nums[zero++]);
        }
    }
};
