class Solution {
public:
  bool kLengthApart(vector<int>& nums, int k) {
    int pre = -1000000000;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        if (i - pre - 1 < k) {
          return false;
        }
        pre = i;
      }
    }
    return true;
  }
};
