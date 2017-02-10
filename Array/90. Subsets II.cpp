// treat duplicated elements as one single element, and it can appearance [0, k] times in a subset(k is the duplicated number).
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ss = {{}};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            int cnt = 0;
            while (i + cnt < nums.size() && nums[i + cnt] == nums[i]) cnt++;
            int oldSize = ss.size();
            for (int j = 0; j < oldSize; j++) {
                vector<int> tmp = ss[j];
                for (int k = 0; k < cnt; k++) {
                    tmp.push_back(nums[i]);
                    ss.push_back(tmp);
                }
            }
            i += cnt;
        }
        return ss;
    }
};
