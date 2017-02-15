// two binary search (lowerbound and upperbound)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        if (nums.empty()) return ret;
        
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
    		int mid = (begin + end) / 2;
    		if (nums[mid] < target) {
    		    begin = mid + 1;
    		}
    		else {
    			end = mid;
    		}
    	}
    	if (nums[begin] != target) return ret;
    	else ret[0] = begin;
    	
    	end = nums.size() - 1;
    	while (begin < end) {
    		int mid = (begin + end) / 2 + 1;
    		if (nums[mid] > target) {
    		    end = mid - 1;
    		}
    	    else {
    			begin = mid;
    		}
    	}
    	ret[1] = end;
    	return ret;
    }
};
