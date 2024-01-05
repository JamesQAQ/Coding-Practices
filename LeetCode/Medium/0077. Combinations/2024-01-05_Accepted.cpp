class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> combination;
    dfs(1, k, n, combination, result);
    return result;
  }

private:
  void dfs(
      int x, int k, int n,
      vector<int>& combination, vector<vector<int>>& result) {
    if (combination.size() == k) {
      result.push_back(combination);
      return;
    }
    for (int i = x; i <= n; i++) {
      combination.push_back(i);
      dfs(i + 1, k, n, combination, result);
      combination.pop_back();
    }
  }
};
