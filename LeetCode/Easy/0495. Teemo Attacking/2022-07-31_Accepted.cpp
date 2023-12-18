class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (duration == 0) return 0;
        int ans = 0;
        int last = -1;
        for (int i = 0; i < timeSeries.size(); i++) {
            int left = timeSeries[i];
            int right = timeSeries[i] + duration - 1;
            last = max(left - 1, last);
            ans += right - last;
            last = right;
        }
        return ans;
    }
};