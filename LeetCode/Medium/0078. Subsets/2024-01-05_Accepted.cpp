class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> subset;
    for (int i = 0; i <= nums.size(); i++) {
      dfs(0, i, subset, nums, result);
    }
    return result;
  }

private:
  void dfs(
      int pos,
      int len,
      vector<int>& subset,
      vector<int>& nums,
      vector<vector<int>>& result) {
    if (subset.size() == len) {
      result.push_back(subset);
      return;
    }
    for (int i = pos; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      dfs(i + 1, len, subset, nums, result);
      subset.pop_back();
    }
  }
};
