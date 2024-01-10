class Solution {
public:
  bool check(vector<int>& nums) {
    nums.push_back(nums[0]);
    bool illegal = false;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        if (illegal) {
          return false;
        }
        illegal = true;
      }
    }
    return true;
  }
};
