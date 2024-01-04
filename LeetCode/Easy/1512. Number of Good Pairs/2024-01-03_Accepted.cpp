class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    vector<int> count(101, 0);
    for (auto num : nums) {
      count[num]++;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
      ans += count[i] * (count[i] - 1) / 2;
    }
    return ans;
  }
};
