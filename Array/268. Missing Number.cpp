// Solution 1 Add up [0, n], then minus all numbers. note: use long long to avoid overflow
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = (n * n + n) / 2;
        for (int num : nums) {
            sum -= num;
        }
        
        return (int)sum;
    }
};

// Solution 2 bit manipulation
// a^a = 0 a^b = b^a a^b^c = a^(b^c)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ret ^= nums[i] ^ i;
        }
        return ret;
    }
};
