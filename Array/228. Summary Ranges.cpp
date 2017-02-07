// pointers to scan the array
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return vector<string>();
        }
        
        vector<string> summary;
        int beg = nums.front();
        int end = beg + 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == end) {
                end++;
            }
            else {
                summary.push_back(summaryStr(beg, end));
                beg = nums[i];
                end = beg + 1;
            }
        }
        summary.push_back(summaryStr(beg, end));
        
        return summary;
    }
    
private:
    string summaryStr(int beg, int end) {
        if (end == beg + 1) {
            return to_string(beg);
        }
        else {
            return to_string(beg) + "->" + to_string(end - 1);
        }
    }
};
