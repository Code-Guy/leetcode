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

int binarySearchLowerBound(vector<int> &nums, int lowerBound)
{
	int begin = 0, end = nums.size() - 1;
	while (begin < end)
	{
		int mid = (begin + end + 1) / 2;
		if (nums[mid] <= lowerBound)
		{
			begin = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	return begin;
}

int binarySearchUpperBound(vector<int> &nums, int upperBound)
{
	int begin = 0, end = nums.size() - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (nums[mid] >= lowerBound)
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	}
	return begin;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        vector<int> firstCol(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            if(matrix[i].empty()) return false;
            firstCol[i] = matrix[i][0];
        }
        int row = binarySearchLowerBound(firstCol, target);
        if (row == -1) return false;
        return binarySearchValue(matrix[row], target) != -1;
    }
    
private:
    int binarySearchLowerBound(const vector<int> &nums, int target)
    {
        if (nums.size() == 0 || target < nums[0]) return -1;
	    int begin = 0, end = nums.size() - 1;
	    while (begin < end)
	    {
		    int mid = (begin + end + 1) / 2;
		    if (nums[mid] <= target)
		    {
			    begin = mid;
		    }
		    else
		    {
			    end = mid - 1;
		    }
	    }
	    return begin;
    }
    
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
};
