class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> count(51, 0);
    for (auto candidate : candidates) {
      count[candidate]++;
    }
    candidates.clear();
    for (int i = 1; i <= 50; i++) {
      if (count[i]) {
        candidates.push_back(i);
      }
    }

    vector<vector<int>> result;
    vector<int> combination;
    dfs(0, target, candidates, combination, result, count);
    return result;
  }

private:
  void dfs(
      int idx,
      int left,
      vector<int>& candidates,
      vector<int>& combination,
      vector<vector<int>>& result,
      vector<int>& count) {
    if (left <= 0) {
      if (left == 0) {
        result.push_back(combination);
      }
      return;
    }
    for (int i = idx; i < candidates.size(); i++) {
      if (count[candidates[i]] > 0) {
        count[candidates[i]]--;
        combination.push_back(candidates[i]);
        dfs(i, left - candidates[i], candidates, combination, result, count);
        combination.pop_back();
        count[candidates[i]]++;
      }
    }
  }
};
