class Solution {
public:
  int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); i++) {
      if (isOk(nums, i)) {
        return i;
      }
    }
    return -1;
  }

private:
  bool isOk(vector<int>& nums, int x) {
    int count = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < x) {
        return count == x;
      }
      count++;
    }
    return count == x;
  }
};
