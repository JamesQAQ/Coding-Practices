class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    map<long long, vector<int>> numMapping;
    for (int i = 0; i < nums.size(); i++) {
      if (numMapping.find(nums[i]) == numMapping.end()) {
        numMapping[nums[i]] = vector<int>();
      }
      numMapping[nums[i]].push_back(i);
    }

    int ans = -nums.size() * (nums.size() - 1) / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        dp[i][j] = 1;
        long long pre = (long long)2 * nums[i] - nums[j];
        if (numMapping.find(pre) != numMapping.end()) {
          for (auto k : numMapping[pre]) {
            if (k < i) {
              dp[i][j] += dp[k][i];
            } else {
              break;
            }
          }
        }
        ans += dp[i][j];
      }
    }
    return ans;
  }
};
