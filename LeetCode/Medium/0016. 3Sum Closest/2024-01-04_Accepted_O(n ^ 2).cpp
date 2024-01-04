class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans = -1000000000;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      int ptr = nums.size() - 1;
      for (int j = i + 1; j < nums.size() - 1; j++) {
        while (ptr > j) {
          if (abs(nums[i] + nums[j] + nums[ptr] - target) < abs(ans - target)) {
            ans = nums[i] + nums[j] + nums[ptr];
          }
          if (ptr - 1 > j
              && abs(nums[i] + nums[j] + nums[ptr - 1] - target)
              <= abs(nums[i] + nums[j] + nums[ptr] - target)) {
            ptr--;
          } else {
            break;
          }
        }
      }
    }
    return ans;
  }
};
