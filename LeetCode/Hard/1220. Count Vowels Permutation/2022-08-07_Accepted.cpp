class Solution {
    int MOD = 1000000007;
    
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp;
        vector<long long> empty(5, 0);
        dp.push_back(empty);
        for (int i = 0; i < 5; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            dp.push_back(empty);
            for (int j = 0; j < 5; j++) {
                if (j == 0) {
                    dp[i][j] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
                } else if (j == 1) {
                    dp[i][j] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
                } else if (j == 2) {
                    dp[i][j] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
                } else if (j == 3) {
                    dp[i][j] = dp[i - 1][2];
                } else {
                    dp[i][j] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 5; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        return ans;
    }
};