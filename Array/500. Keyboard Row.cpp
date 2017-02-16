class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        unordered_set<char> s[] = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
            {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
        };
        
        for (string word : words) {
            if (word.empty()) {
                ret.push_back(word);
                continue;
            }
            int si = 0;
            for (; si < 3; si++) {
                if (s[si].find(tolower(word[0])) != s[si].end()) break;
            }
            int i = 1;
            for (; i < word.size(); i++) {
                if (s[si].find(tolower(word[i])) == s[si].end()) break;
            }
            if (i == word.size()) ret.push_back(word);
        }
        return ret;
    }
};
