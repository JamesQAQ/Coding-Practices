class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp = vector<vector<int>>(
        2, vector<int>(text2.length() + 1, 0));
    for (int i = 1; i <= text1.length(); i++) {
      for (int j = 1; j <= text2.length(); j++) {
        int idx = i % 2;
        dp[idx][j] = max(dp[1 - idx][j], dp[idx][j - 1]);
        if (text1[i - 1] == text2[j - 1]) {
          dp[idx][j] = max(dp[idx][j], dp[1 - idx][j - 1] + 1);
        }
      }
    }
    return dp[text1.length() % 2][text2.length()];
  }
};
