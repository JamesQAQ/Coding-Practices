class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans = -1000000000;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size() - 1; j++) {
        int findVal = target - nums[i] - nums[j];
        auto it = lower_bound(nums.begin() + j + 1, nums.end(), findVal);
        if (it == nums.end()) {
          it--;
        }
        if (abs(nums[i] + nums[j] + *it - target) < abs(ans - target)) {
          ans = nums[i] + nums[j] + *it;
        }
        it--;
        if (distance(nums.begin(), it) > j) {
          if (abs(nums[i] + nums[j] + *it - target) < abs(ans - target)) {
            ans = nums[i] + nums[j] + *it;
          }
        }
      }
    }
    return ans;
  }
};
