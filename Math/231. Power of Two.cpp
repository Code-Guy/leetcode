// n &= n - 1可以消除n二进制串最右边的1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n != 0 && n != INT_MIN && (n & (n - 1)) == 0;
    }
};
