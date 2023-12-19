/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <algorithm>
#include <iostream>

bool cmp(Interval a, Interval b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector <Interval> ans;
        if (n > 0){
            stable_sort(intervals.begin(), intervals.end(), cmp);
            int l = intervals[0].start, r = intervals[0].end;
            for (int i = 1; i < n; i++){
                if (intervals[i].start <= r)
                    r = max(r, intervals[i].end);
                else{
                    ans.push_back(Interval(l, r));
                    l = intervals[i].start, r = intervals[i].end;
                }
            }
            ans.push_back(Interval(l, r));
        }
        return ans;
    }
};
