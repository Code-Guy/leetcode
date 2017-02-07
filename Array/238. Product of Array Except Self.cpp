// Solution 1 two loops
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;
        product.resize(nums.size());
        int lp = 1;
        product[0] = lp;
        for (int i = 0; i < nums.size() - 1; i++) {
            lp *= nums[i];
            product[i + 1] = lp;
        }
        
        int rp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product[i] *= rp;
            rp *= nums[i];
        }
        
        return product;
    }
};

// Solution 2 one single loop
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> product(n, 1);
        int lp = 1;
        int rp = 1;

        for (int i = 0; i < n; i++) {
            product[i] *= lp;
            product[n - i - 1] *= rp;
            lp *= nums[i];
            rp *= nums[n - i - 1];
        }

        return product;
    }
};
