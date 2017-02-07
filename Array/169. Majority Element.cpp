// Boyer-Moore Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = 0;
        int c = 0;
        for (int num : nums) {
            if (num == m) {
                c++;
            }
            else if (c == 0) {
                m = num;
            }
            else {
                c--;
            }
        }
        
        c = 0;
        for (int num : nums) {
            if (num == m) {
                c++;
            }
        }
        
        return m;
    }
};
