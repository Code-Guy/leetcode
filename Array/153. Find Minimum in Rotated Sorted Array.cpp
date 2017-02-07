// binary search 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            if (nums[begin] < nums[end]) {
                return nums[begin];
            }
            
            int mid = (begin + end) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            }
            else {
                begin = mid + 1;
            }
        }
        
        return nums[begin];
    }
};
