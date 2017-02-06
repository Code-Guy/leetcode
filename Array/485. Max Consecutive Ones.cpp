class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
            }
            else if (num == 0) {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        
        maxCount = max(maxCount, count);
        return maxCount;
    }
};
