class Solution {
public:
  int subsetXORSum(vector<int>& nums) {
    int ans = 0;
    dfs(0, nums, 0, ans);
    return ans;
  }

private:
  void dfs(int idx, vector<int>& nums, int val, int& ans) {
    if (idx == nums.size()) {
      ans += val;
      return;
    }
    dfs(idx + 1, nums, val, ans);
    dfs(idx + 1, nums, val ^ nums[idx], ans);
  }
};
