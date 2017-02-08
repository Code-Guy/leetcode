// max subarray algorithm (Kadane algorithm)
// 1. positive sum result array can be empty
int maxSubArray(int a[], int n) {
    int localMax = 0, globalMax = 0;
    for (int i = 0; i < n; i++) {
        localMax = max(0, local + a[i]);
        globalMax = max(globalMax, localMax);
    }
    return globalMax;
}
// 2. arbitrary sum result array can't be empty
int maxSubArray(int a[], int n) {
    int localMax = a[0], globalMax = a[0];
    for (int i = 1; i < n; i++) {
        localMax = max(a[i], local + a[i]);
        globalMax = max(globalMax, localMax);
    }
    return globalMax;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxPro = max(maxPro, price - minPrice);
        }
        return maxPro;
    }
};
