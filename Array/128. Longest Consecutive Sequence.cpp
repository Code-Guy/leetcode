// unordered_set and unordered_map are all based on hash table, which find O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num : nums) {
            if (s.find(num) == s.end()) continue;
            int prev = num - 1, next = num + 1;
            while (s.find(prev) != s.end()) s.erase(prev--);
            while (s.find(next) != s.end()) s.erase(next++);
            s.erase(num);
            maxLen = max(maxLen, next - prev - 1);
        }
        return maxLen;
    }
};
