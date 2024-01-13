class Solution {
public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    int required = 1;
    for (auto num : nums) {
      required = max(required, num);
      ans += required++ - num;
    }
    return ans;
  }
};
