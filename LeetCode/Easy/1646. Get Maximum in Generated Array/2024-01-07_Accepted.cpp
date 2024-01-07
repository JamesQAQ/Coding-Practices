class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n == 0) {
      return 0;
    }
    vector<int> nums(n + 1);
    nums[0] = 0;
    nums[1] = 1;
    int ans = max(nums[0], nums[1]);
    for (int i = 2; i <= n; i++) {
      nums[i] = nums[i / 2] + (i % 2 ? nums[i / 2 + 1] : 0);
      ans = max(ans, nums[i]);
    }
    return ans;
  }
};
