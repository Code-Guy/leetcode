// two pointers head and tail
// note that sorted array has a lot of useful properties
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices;
        int begin = 0, end = numbers.size() - 1;
        while (begin != end) {
            int sum = numbers[begin] + numbers[end];
            if (sum < target) {
                begin++;
            }
            else if (sum > target) {
                end--;
            }
            else {
               indices.push_back(begin + 1);
               indices.push_back(end + 1);
               break;
            }
        }
        
        return indices;
    }
};
