class Solution {
public:
  int findClosestNumber(vector<int>& nums) {
    int min_abs_val = 100001;
    int ans;
    for (auto num : nums) {
      if (abs(num) < min_abs_val || (abs(num) == min_abs_val && num > ans)) {
        min_abs_val = abs(num);
        ans = num;
      }
    }
    return ans;
  }
};
