class Solution {
private:
  int _MAX = 1000000000;

public:
  int minCost(string colors, vector<int>& neededTime) {
    vector<int> dp(27, _MAX);
    dp[0] = 0;
    for (int i = 0; i < colors.length(); i++) {
      int curVal = colors[i] - 'a' + 1;
      int minVal = _MAX;
      for (int j = 0; j < 27; j++) {
        if (j != curVal) {
          minVal = min(minVal, dp[j]);
          dp[j] += neededTime[i];
        }
      }
      dp[curVal] = min(minVal, dp[curVal] + neededTime[i]);
    }

    int ans = _MAX;
    for (int i = 0; i < 27; i++) {
      ans = min(ans, dp[i]);
    }
    return ans;
  }
};
