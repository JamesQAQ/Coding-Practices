class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combination;
    dfs(0, target, candidates, combination, result);
    return result;
  }

private:
  void dfs(
      int idx,
      int left,
      vector<int>& candidates,
      vector<int>& combination,
      vector<vector<int>>& result) {
    if (left <= 0) {
      if (left == 0) {
        result.push_back(combination);
      }
      return;
    }
    for (int i = idx; i < candidates.size(); i++) {
      combination.push_back(candidates[i]);
      dfs(i, left - candidates[i], candidates, combination, result);
      combination.pop_back();
    }
  }
};
