class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<vector<int>> result;
    vector<int> permutation;
    dfs(permutation, nums, used, result);
    return result;
  }

private:
  void dfs(
      vector<int>& permutation,
      vector<int>& nums,
      vector<bool>& used,
      vector<vector<int>>& result) {
    if (permutation.size() == nums.size()) {
      result.push_back(permutation);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!used[i]) {
        used[i] = true;
        permutation.push_back(nums[i]);
        dfs(permutation, nums, used, result);
        permutation.pop_back();
        used[i] = false;
      }
    }
  }
};
