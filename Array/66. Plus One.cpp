// Solution 1 经典A+B，有carry进位
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

// Solution 2 利用+1(+n,n属于[0,10])的特性
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
