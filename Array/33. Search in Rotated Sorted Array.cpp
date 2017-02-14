// binary search
int binarySearchValue(vector<int> &nums, int target)
{
	int begin = 0, end = nums.size() - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (nums[mid] < target)
		{
			begin = mid + 1;
		}
		else if (nums[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int binarySearchValue(vector<int> &nums, int target)
{
	int begin = 0, end = nums.size() - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (nums[mid] < target)
		{
			begin = mid + 1;
		}
		else if (nums[mid] > target)
		{
			end = mid
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            
            if (nums[mid] == target) return mid;
            if (nums[end] == target) return end;
            
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
                return -1;
            }
        }
        return -1;
    }
};
