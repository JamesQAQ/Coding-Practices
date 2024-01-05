class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto lit = lower_bound(nums.begin(), nums.end(), target);
    auto uit = upper_bound(nums.begin(), nums.end(), target);
    if (lit == uit) {
      return {-1, -1};
    }
    return {
        (int)distance(nums.begin(), lit),
        (int)distance(nums.begin(), uit) - 1};
  }
};
