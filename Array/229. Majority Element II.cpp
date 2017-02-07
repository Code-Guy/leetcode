// Majority Voting Boyer-Moore Majority Vote Algorithm's elaboration, find more than n/k times major numbers
// use two passes k-1 counters and tmps
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> m;
        int m1 = 0, m2 = 0;
        int c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == m1) {
                c1++;
            }
            else if (num == m2) {
                c2++;
            }
            else if (c1 == 0) {
                m1 = num;
                c1 = 1;
            }
            else if (c2 == 0) {
                m2 = num;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        c1 = 0;
        c2 = 0;
        for (int num : nums) {
            if (num == m1) {
                c1++;
            }
            else if(num == m2) {
                c2++;
            }
        }
        
        if (c1 > nums.size() / 3) {
            m.push_back(m1);
        }
        if (c2 > nums.size() / 3) {
            m.push_back(m2);
        }
        
        return m;
    }
};
