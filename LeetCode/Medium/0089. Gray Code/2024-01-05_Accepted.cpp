class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> result;
    vector<bool> visited(1 << n, false);
    result.push_back(0);
    visited[0] = true;
    dfs(0, n, visited, result);
    return result;
  }

private:
  void dfs(int x, int n, vector<bool>& visited, vector<int>& result) {
    if (result.size() == (1 << n)) {
      return;
    }
    for (int i = 0; i < n; i++) {
      int next = x ^ (1 << i);
      if (!visited[next]) {
        visited[next] = true;
        result.push_back(next);
        dfs(next, n, visited, result);
        if (result.size() == (1 << n)) {
          return;
        }
        result.pop_back();
        visited[next] = false;
      }
    }
  }
};
