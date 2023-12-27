class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> ans;
    int curNumber = 0;
    for (int i = 0; i < nums.size(); i++) {
      curNumber = (curNumber * 2 + nums[i]) % 5;
      ans.push_back(curNumber == 0);
    }
    return ans;
  }
};
