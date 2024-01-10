class Solution {
public:
  int sumOfUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    nums.push_back(101);
    int ans = 0;
    int cur = 0;
    int count = 0;
    for (auto num : nums) {
      if (num != cur) {
        if (count == 1) {
          ans += cur;
        }
        cur = num;
        count = 0;
      }
      count++;
    }
    return ans;
  }
};
