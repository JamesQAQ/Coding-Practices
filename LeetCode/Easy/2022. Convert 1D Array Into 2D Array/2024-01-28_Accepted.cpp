class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> result;
    if (m * n != original.size()) {
      return result;
    }
    int idx = 0;
    for (int i = 0; i < m; i++) {
      result.push_back(vector<int>(n));
      for (int j = 0; j < n; j++) {
        result[i][j] = original[idx++];
      }
    }
    return result;
  }
};
