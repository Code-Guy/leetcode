// binary search 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        while(begin < end) {
            int mid = (begin + end) / 2;
            
            if (nums[mid] > nums[end]) {
                begin = mid + 1;
            }
            else if (nums[mid] < nums[end]) {
                end = mid;
            }
        }
        return nums[begin];
    }
};
