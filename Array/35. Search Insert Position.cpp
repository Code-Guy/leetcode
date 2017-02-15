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

int binarySearchLowerBound(vector<int> &nums, int lowerBound)
{
	int begin = 0, end = nums.size() - 1;
	while (begin < end)
	{
		int mid = (begin + end + 1) / 2;
		if (nums[mid] > lowerBound)
		{
			end = mid - 1;
		}
		else
		{
			begin = mid;
		}
	}
	return begin;
}

int binarySearchUpperBound(vector<int> &nums, int lowerBound)
{
	int begin = 0, end = nums.size() - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (nums[mid] < lowerBound)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
	return begin;
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size();
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] < target) {
                begin = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return begin;
    }
};
