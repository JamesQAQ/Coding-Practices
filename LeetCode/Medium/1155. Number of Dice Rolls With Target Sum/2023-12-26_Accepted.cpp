class Solution {
public:
  int numRollsToTarget(int n, int k, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int sum = target; sum >= 0; sum--) {
        dp[sum] = 0;
        for (int num = 1; num <= k; num++) {
          if (sum - num < 0) {
            break;
          }
          dp[sum] = (dp[sum] + dp[sum - num]) % 1000000007;
        }
      }
    }
    return dp[target];
  }
};
