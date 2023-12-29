class Solution {
public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    vector<vector<int>> dp(d + 1);
    for (int i = 0; i <= d; i++) {
      dp[i] = vector<int>(jobDifficulty.size() + 1, INT_MAX);
    }
    dp[0][0] = 0;
    for (int i = 0; i < jobDifficulty.size(); i++) {
      int maxDifficulty = 0;
      for (int j = i; j < jobDifficulty.size(); j++) {
        maxDifficulty = max(maxDifficulty, jobDifficulty[j]);
        for (int k = 0; k < d; k++) {
          if (dp[k][i] != INT_MAX) {
            dp[k + 1][j + 1] = min(dp[k + 1][j + 1], dp[k][i] + maxDifficulty);
          }
        }
      }
    }
    if (dp[d][jobDifficulty.size()] == INT_MAX) {
      return -1;
    }
    return dp[d][jobDifficulty.size()];
  }
};
