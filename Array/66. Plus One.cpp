class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> sum(n);
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int d = digits[i] + carry;
            if (i == n - 1) d++;
            carry = d / 10;
            sum[i] = d % 10;
        }
        if (carry != 0) {
            sum.insert(sum.begin(), 1);
        }
        return sum;
    }
};
