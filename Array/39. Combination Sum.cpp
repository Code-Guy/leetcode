// classical backtracing 
// for solving constraint satisfaction problems
// traversing the paths of graph
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> combination;
        
        combinationSum(candidates, target, 0, combinations, combination);
        
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
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, combinations, combination);
            combination.pop_back();
        }
    }
};
