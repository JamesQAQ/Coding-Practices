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
        Interval mergeInterval = newInterval;
        bool merge = false;
        vector<Interval> ans;
        for (int i = 0; i < intervals.size(); i++) {
            Interval interval = intervals[i];
            if (interval.start > newInterval.end && !merge) {
                merge = true;
                ans.push_back(mergeInterval);
            }
            if (interval.end < newInterval.start || interval.start > newInterval.end) {
                ans.push_back(interval);
            }
            else {
                mergeInterval.start = min(mergeInterval.start, interval.start);
                mergeInterval.end = max(mergeInterval.end, interval.end);
            }
        }
        if (!merge)
            ans.push_back(mergeInterval);
        return ans;
    }
};
