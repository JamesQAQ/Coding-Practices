class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> result;
    int remain = 0;
    for (int i = 0; i < nums.size(); i++) {
      remain = (remain * 2 + nums[i]) % 5;
      result.push_back(remain == 0);
    }
    return result;
  }
};
