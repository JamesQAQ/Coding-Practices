class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // `dp[i]` = A solution which has length `i` and ends with `dp[i]`.
        // Use greedy method that we should keep `dp[i]` as small as possible. 
        vector<int> dp;
        vector<int> result;
        for (auto obstacle: obstacles) {
            if (dp.size() == 0 || obstacle >= dp.back()) {
                dp.push_back(obstacle);
                result.push_back(dp.size());
            } else {
                auto it = upper_bound(dp.begin(), dp.end(), obstacle);
                *it = obstacle;
                result.push_back(it - dp.begin() + 1);
            }
        }
        return result;
    }
};
