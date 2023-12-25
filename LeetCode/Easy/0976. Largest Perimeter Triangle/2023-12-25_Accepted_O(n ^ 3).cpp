class Solution {
public:
  int largestPerimeter(vector<int>& nums) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i > 1; i--) {
      if (nums[i] * 2 + 1 < ans) {
        break;
      }
      for (int j = i - 1; j > 0; j--) {
        if (nums[j] < nums[i] - nums[j] + 1) {
          break;
        }
        for (int k = j - 1; k >= 0; k--) {
          if (nums[k] < nums[i] - nums[j] + 1) {
            break;
          }
          ans = max(ans, nums[i] + nums[j] + nums[k]);
        }
      }
    }
    return ans;
  }
};
