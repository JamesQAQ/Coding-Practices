class Solution {
public:
  int findFinalValue(vector<int>& nums, int original) {
    stable_sort(nums.begin(), nums.end());
    int ans = original;
    auto it = lower_bound(nums.begin(), nums.end(), ans);
    while (it != nums.end() && *it == ans) {
      ans *= 2;
      it = lower_bound(nums.begin(), nums.end(), ans);
    }
    return ans;
  }
};
