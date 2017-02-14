// same as Find Minimum in Rotated Sorted Array II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            
            if (nums[mid] == target) return true;
            if (nums[end] == target) return true;
            
            if (nums[mid] > nums[end]) {
                if (target > nums[end] && target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    begin = mid + 1;
                }
            }
            else if (nums[mid] < nums[end]) {
                if (target > nums[mid] && target < nums[end]) {
                    begin = mid + 1;
                }
                else {
                    end = mid - 1; 
                }
            }
            else {
                if (mid == end) return false;
                else end--;
            }
        }
        return false;
    }
};
