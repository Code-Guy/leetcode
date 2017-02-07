// O(n) two pointers
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int b = 0;
        int sum = 0;
        int minLen = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                minLen = min(minLen, i - b + 1);
                sum -= nums[b++];
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};
