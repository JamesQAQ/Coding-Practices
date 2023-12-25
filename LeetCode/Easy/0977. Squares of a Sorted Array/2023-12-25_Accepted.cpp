class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans(nums.size());
    int lptr = 0, rptr = nums.size() - 1;
    for (int i = ans.size() - 1; i >= 0; i--) {
      if (nums[lptr] * nums[lptr] > nums[rptr] * nums[rptr]) {
        ans[i] = nums[lptr] * nums[lptr];
        lptr++;
      } else {
        ans[i] = nums[rptr] * nums[rptr];
        rptr--;
      }
    }
    return ans;
  }
};
