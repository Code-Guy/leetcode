class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) { // 特殊情况判断
            return 0;
        }
            
        int poisonedDuration = timeSeries.size() * duration;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            int span = timeSeries[i + 1] - timeSeries[i];
            poisonedDuration -= span > duration ? 0 : duration - span;
        }
        
        return poisonedDuration;
    }
};
