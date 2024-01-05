class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(21, 0);
    for (auto num : nums) {
      count[num + 10]++;
    }
    nums.clear();
    for (int i = 0; i < 21; i++) {
      if (count[i]) {
        nums.push_back(i);
      }
    }

    vector<vector<int>> result;
    vector<int> subset;
    for (int i = 0; i <= n; i++) {
      dfs(0, i, subset, nums, count, result);
    }
    return result;
  }

private:
  void dfs(
      int pos,
      int len,
      vector<int>& subset,
      vector<int>& nums,
      vector<int>& count,
      vector<vector<int>>& result) {
    if (subset.size() == len) {
      result.push_back(subset);
      return;
    }
    for (int i = pos; i < nums.size(); i++) {
      if (count[nums[i]]) {
        count[nums[i]]--;
        subset.push_back(nums[i] - 10);
        dfs(i, len, subset, nums, count, result);
        subset.pop_back();
        count[nums[i]]++;
      }
    }
  }
};
