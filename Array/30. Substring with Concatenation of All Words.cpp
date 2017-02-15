// use two unordered_maps 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indices;
        unordered_map<string, int> count;
        for (string word : words) {
            count[word]++;
        }
        int ns = s.size(), nws = words.size(), nw = words[0].size();
        for (int i = 0; i < ns - nws * nw + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < nws; j++) {
                string word = s.substr(i + j * nw, nw);
                if (count.find(word) != count.end()) {
                    seen[word]++;
                    if (seen[word] > count[word]) break;
                }
                else break;
            }
            if (j == nws) indices.push_back(i);
        }
        return indices;
    }
};
