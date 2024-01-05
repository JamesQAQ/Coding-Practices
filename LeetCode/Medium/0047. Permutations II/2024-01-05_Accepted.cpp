class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    vector<int> permutation;
    dfs(permutation, n, nums, count, result);
    return result;
  }

private:
  void dfs(
      vector<int>& permutation,
      int n,
      vector<int>& nums,
      vector<int>& count,
      vector<vector<int>>& result) {
    if (permutation.size() == n) {
      result.push_back(permutation);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (count[nums[i]]) {
        count[nums[i]]--;
        permutation.push_back(nums[i] - 10);
        dfs(permutation, n, nums, count, result);
        permutation.pop_back();
        count[nums[i]]++;
      }
    }
  }
};
