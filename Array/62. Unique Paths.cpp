class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> s(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                s[i] += s[i - 1];
            }
        }
        return s[m - 1];
    }
};
