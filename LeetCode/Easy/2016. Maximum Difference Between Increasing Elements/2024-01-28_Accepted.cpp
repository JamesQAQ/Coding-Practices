class Solution {
public:
  int maximumDifference(vector<int>& nums) {
    int minNum = nums[0];
    int ans = -1;
    for (auto num : nums) {
      if (num > minNum) {
        ans = max(ans, num - minNum);
      }
      minNum = min(minNum, num);
    }
    return ans;
  }
};
