// dp state transition equation: s[k][i] = max(s[k][i-1], p[i] - p[j] + s[k-1][j]) = max(s[k][i-1], p[i] + max(s[k-1][j] - p[j]))
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int maxProf = 0;
        int n = prices.size();
        int k = 2;
        vector<vector<int>> s(k+1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int tmpMax = s[i-1][0] - prices[0];
            for (int j = 1; j < n; j++) {
                s[i][j] = max(s[i][j-1], prices[j] + tmpMax);
                maxProf = max(maxProf, s[i][j]);
                tmpMax = max(tmpMax, s[i-1][j] - prices[j]);
            }
        }
        return maxProf;
    }
};
