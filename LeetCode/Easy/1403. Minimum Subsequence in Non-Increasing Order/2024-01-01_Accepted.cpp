class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end(), cmp);
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    int curSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      curSum += nums[i];
      if (curSum > sum / 2) {
        return vector<int>(nums.begin(), nums.begin() + i + 1);
      }
    }
    return {};
  }

private:
  static bool cmp(int i, int j) {
    return i > j;
  }
};
