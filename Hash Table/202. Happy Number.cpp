// Solution 1 hash table check cycle
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
// floyd cycle detection algorithm
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
           slow = iterate(slow);
           fast = iterate(iterate(fast));
        } while (slow != fast);
        return slow == 1;
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
