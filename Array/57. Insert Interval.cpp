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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) return vector<Interval>{newInterval};
        int begin = 0, end = intervals.size() - 1;
        int left, right;
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (intervals[mid].end < newInterval.start) {
                begin = mid + 1;
            }
            else {
                end = mid;
            }
        }
        left = begin;
        begin = 0, end = intervals.size() - 1;
        while (begin < end) {
            int mid = (begin + end) / 2 + 1;
            if (intervals[mid].start > newInterval.end) {
                end = mid - 1;
            }
            else {
                begin = mid;
            }
        }
        right = end;
        
        int el, er;
        Interval insertion;
        
        if (intervals[left].end < newInterval.start && intervals[right].start > newInterval.end) {
            el = left + 1;
            er = right;
            insertion = newInterval;
        }
        else if (intervals[left].end < newInterval.start) {
            el = left + 1;
            er = right + 1;
            insertion = Interval(newInterval.start, max(intervals[right].end, newInterval.end));
        }
        else if (intervals[right].start > newInterval.end) {
            el = left;
            er = right;
            insertion = Interval(min(intervals[left].start, newInterval.start), newInterval.end);
        }
        else {
            el = left;
            er = right + 1;
            insertion = Interval(min(intervals[left].start, newInterval.start), max(intervals[right].end, newInterval.end));
        }
        if (el != er) {
            intervals.erase(intervals.begin() + el, intervals.begin() + er);
        }
        intervals.insert(intervals.begin() + el, insertion);
        return intervals;
    }
};
