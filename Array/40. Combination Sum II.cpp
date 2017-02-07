// note: skip duplicated candidates
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> combination;
        
        combinationSum(candidates, target, 0, combinations, combination);
        
        // can also remove duplicates in result, but low efficency
        //sort(combinations.begin(), combinations.end());
        //combinations.erase(unique(combinations.begin(), combinations.end()), combinations.end());
        return combinations;
    }
    
private:
    void combinationSum(const vector<int>& candidates, int target, int begin, 
        vector<vector<int>> &combinations, vector<int> &combination)
    {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            if (i != begin && candidates[i] == candidates[i - 1]) {
                continue;
            }
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i + 1, combinations, combination);
            combination.pop_back();
        }
    }
};
