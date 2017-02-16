// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> b(n, true);
        int sn = sqrt(n - 1);
        for (int i = 2; i <= sn; i++) {
            if (b[i]) {
                for (int j = i * i; j < n; j += i) {
                    b[j] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) cnt += b[i];
        return cnt;
    }
};
