// Solution 1 Binary Search Pigeon Hole Principle
// mid = beg + (end - beg) / 2
// a: beg <= end beg = mid + 1 end = mid - 1 b: beg < end beg = mid + 1 end = mid
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            int cnt = 0;
            for (int num : nums) {
                if (num <= mid) {
                    cnt++;
                }
            }
            
            if (cnt > mid) {
                end = mid - 1;
            }
            else {
                beg = mid + 1;
            }
        }
        
        return beg;
    }
};

// Solution 2 Floyd's Cycle Finding algorithm
// hare and tortoise
// slow(one step) and fast(two step) pointer, meets twice
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
