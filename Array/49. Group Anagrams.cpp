// the default value of new created value is the default type value
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> umap;
        for (string str : strs) {
            umap[strIndex(str)].push_back(str);
        }
        for (const auto &iter : umap) {
            anagrams.push_back(iter.second);
        }
        return anagrams;
    }
    
private:
    string strIndex(string str) {
        string index;
        vector<int> cnt(26, 0); 
        for (char c : str)  cnt[c - 'a']++;
        for (int n : cnt) {
            index += to_string(n);
        }
        return index;
    }
};
