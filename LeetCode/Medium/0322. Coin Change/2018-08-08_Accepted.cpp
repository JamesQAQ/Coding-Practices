class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            for (int j = coin; j <= amount; j++) {
                if (dp[j - coin] != -1) {
                    if (dp[j] == -1 || dp[j - coin] + 1 < dp[j]) {
                        dp[j] = dp[j - coin] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};