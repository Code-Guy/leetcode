class Solution {
public:
    string multiply(string num1, string num2) {
        string mult(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int tmp = mult[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + carry;
                mult[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            mult[i] += carry;
        }
        size_t firstNonZeroPos = mult.find_first_not_of('0');
        if (firstNonZeroPos != string::npos) return mult.substr(firstNonZeroPos);
        return "0";
    }
};
