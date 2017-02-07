// O(logn) binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            bool lp = mid == 0 || nums[mid] > nums[mid - 1];
            bool rp = mid == nums.size() - 1 || nums[mid] > nums[mid + 1];
            if (lp && rp) {
                return mid;
            }
            else if (!rp) {
                begin = mid + 1;
            }
            else if (!lp) {
                end = mid - 1;
            }
        }
        
        return -1;
    }
};

// a more concise standard binary search solution
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] < nums[mid + 1]) {
                begin = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        return begin;
    }
};
