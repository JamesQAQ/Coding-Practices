class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
    bool ans = false;
    ans |= isIncreasing(nums);
    reverse(nums.begin(), nums.end());
    ans |= isIncreasing(nums);
    return ans;
  }

private:
  bool isIncreasing(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] > nums[i]) {
        return false;
      }
    }
    return true;
  }
};
