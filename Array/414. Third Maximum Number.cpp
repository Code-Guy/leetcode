class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = numeric_limits<long long>::min();   
        long long max2 = numeric_limits<long long>::min();
        long long max3 = numeric_limits<long long>::min();
        
        for (int num : nums) {
            if (num == max1 || num == max2 || num == max3) {
                continue;
            }
            
            if (num > max3) {
                if (num > max2) {
                    max3 = max2;
                    if (num > max1) {
                        max2 = max1;
                        max1 = num;
                    }
                    else {
                        max2 = num;
                    }
                }
                else {
                    max3 = num;
                }
            }
        }
        
        max3 = max3 == numeric_limits<long long>::min() ? max1 : max3;
        
        return (int)max3;
    }
};
