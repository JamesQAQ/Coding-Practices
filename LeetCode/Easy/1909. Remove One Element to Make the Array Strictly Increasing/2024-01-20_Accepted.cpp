class Solution {
public:
  bool canBeIncreasing(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] <= nums[i - 1]) {
        return isValid(nums, i - 1) || isValid(nums, i);
      }
    }
    return true;
  }

private:
  bool isValid(vector<int>& nums, int ignore) {
    int pre = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i != ignore) {
        if (nums[i] <= pre) {
          return false;
        }
        pre = nums[i];
      }
    }
    return true;
  }
};
