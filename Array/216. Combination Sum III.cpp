class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> combination;
        combinationSum(k, n, 0, combinations, combination);

        return combinations;
    }
    
private:
    void combinationSum(int k, int n, int begin, 
        vector<vector<int>> &combinations, vector<int> &combination)
    {
        if (combination.size() == k) {
            if (n == 0) {
                combinations.push_back(combination);
            }
            return;
        }

        for (int i = begin; i < 9 && n >= i + 1; i++) {
            combination.push_back(i + 1);
            combinationSum(k, n - (i + 1), i + 1, combinations, combination);
            combination.pop_back();
        }
    }
};
