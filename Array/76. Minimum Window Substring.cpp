// 1. Use two pointers: start and end to represent a window.
// 2. Move end to find a valid window.
// 3. When a valid window is found, move start to find a smaller window.
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) m[c]++;
        int begin = 0, end = 0, minBegin = 0, minLen = INT_MAX;
        int counter = t.size(), size = s.size();
        
        while (end < size) {
            if (m[s[end++]]-- > 0) counter--;
            while (counter == 0) {
                if (end - begin < minLen) {
                    minBegin = begin;
                    minLen = end - begin;
                }
                if (m[s[begin++]]++ == 0) counter++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minBegin, minLen);
    }
};
