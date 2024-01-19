class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    vector<vector<int>> dp = vector<vector<int>>(
        2, vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
      int idx = i % 2;
      for (int j = 0; j < matrix[0].size(); j++) {
        dp[idx][j] = dp[1 - idx][j] + matrix[i][j];
        if (j > 0) {
          dp[idx][j] = min(dp[idx][j], dp[1 - idx][j - 1] + matrix[i][j]);
        }
        if (j < matrix[0].size() - 1) {
          dp[idx][j] = min(dp[idx][j], dp[1 - idx][j + 1] + matrix[i][j]);
        }
      }
    }
    int ans = INT_MAX;
    for (auto num : dp[(matrix.size() - 1) % 2]) {
      ans = min(ans, num);
    }
    return ans;
  }
};
