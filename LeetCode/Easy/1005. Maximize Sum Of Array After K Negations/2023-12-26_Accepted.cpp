class Solution {
public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int idx = 0;
    while (k > 0 && idx < nums.size() && nums[idx] < 0) {
      nums[idx] = -nums[idx];
      idx++;
      k--;
    }
    if (k % 2 != 0) {
      if (idx == nums.size()) {
        idx--;
      } else if (idx > 0 && nums[idx - 1] < nums[idx]) {
        idx--;
      }
      nums[idx] = -nums[idx];
    }
    for (int i = 0; i < nums.size(); i++) {
      ans += nums[i];
    }
    return ans;
  }
};
