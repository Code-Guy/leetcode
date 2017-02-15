// sort can make things easier
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n < 2) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (intervals[i].start > ret.back().end) {
                    ret.push_back(intervals[i]);
            }
            else {
                ret.back().end = max(ret.back().end, intervals[i].end);
            }
        }
        return ret;
    }
};
