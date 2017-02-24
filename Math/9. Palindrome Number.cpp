// sum up the reversed right part
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int rsum = 0;
        while (x > rsum) {
            rsum = rsum * 10 + x % 10;
            x /= 10;
        }
        return x == rsum || x == rsum / 10;
    }
};
