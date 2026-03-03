class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;
    for (auto n : nums) {
      if (n != 2) {
        int val = 1;
        while ((val << 1) & n) {
          val <<= 1;
        }
        ans.push_back(n - val);
      } else {
        ans.push_back(-1);
      }
    }
    return ans;
  }
};
