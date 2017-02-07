// Solution 1 Reverse first n-k elements, reverse last k elements, and reverse all elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// Solution 2 Swap first k elements and last k elements, then reduce n and k, rotate again
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int b = 0; k %= n; n -= k, b += k) {
            for (int i = 0; i < k; i++) {
                swap(nums[b + i], nums[b + n - k + i]);
            }
        }
    }
};
