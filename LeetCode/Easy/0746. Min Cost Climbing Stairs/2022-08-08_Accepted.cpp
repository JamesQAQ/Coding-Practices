class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = 1e9;
            for (int j = 1; j <= 2; j++) {
                dp[i] = min(dp[i], dp[i - j] + cost[i - j]);
            }
        }
        return dp[dp.size() - 1];
    }
};