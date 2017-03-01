// bit manipulation increment
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long long dvd = labs(dividend), dvs = labs(divisor);
        int ret = 0;
        while (dvd >= dvs) {
            long long tmp = dvs;
            int mult = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                mult <<= 1;
            }
            dvd -= tmp;
            ret += mult;
        }
        return sign * ret;
    }
};
