class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        do {
            if (s.find(n) != s.end()) return false;
            s.insert(n);
            n = iterate(n);
        } while (n != 1);
        
        return true;
    }
    
private:
    int iterate(int n) {
        int ret = 0;
        while (n) {
            ret += (n % 10) * (n % 10);
            n /= 10;
        }
        return ret;
    }
};
