class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[1] = false;
        for (int i = 2; i <= n; i++) {
            dp[i] = false;
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if (!dp[i - j]) dp[i] = true;
                    if (j > 1 && !dp[i - i / j]) dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};