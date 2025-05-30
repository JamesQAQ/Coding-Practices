class Solution {
public:
  int countElements(vector<int>& nums) {
    stable_sort(nums.begin(), nums.end());
    if (nums[0] == nums[nums.size() - 1]) {
      return 0;
    }
    int sum = 2;
    for (int i = 0; i < nums.size() - 1 && nums[i] == nums[i + 1]; i++) {
      sum++;
    }
    for (int i = nums.size() - 1; i > 0 && nums[i] == nums[i - 1]; i--) {
      sum++;
    }
    return nums.size() - sum;
  }
};