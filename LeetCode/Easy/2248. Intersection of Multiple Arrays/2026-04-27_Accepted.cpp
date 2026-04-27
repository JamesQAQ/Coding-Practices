class Solution {
public:
  vector<int> intersection(vector<vector<int>>& nums) {
    vector<int> count(1001, 0);
    for (auto arr : nums) {
      for (auto num : arr) {
        count[num]++;
      }
    }
    
    vector<int> ans;
    for (int i = 1; i <= 1000; i++) {
      if (count[i] == nums.size()) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
