class Solution {
public:
  bool checkValid(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      if (!checkColumn(matrix, i) || !checkRow(matrix, i)) {
        return false;
      }
    }
    return true;
  }

private:
  bool checkColumn(vector<vector<int>>& matrix, int column) {
    int n = matrix.size();
    vector<bool> exists(n + 1, false);
    for (int i = 0; i < n; i++) {
      int val = matrix[i][column];
      if (exists[val]) {
        return false;
      }
      exists[val] = true;
    }
    return true;
  }

  bool checkRow(vector<vector<int>>& matrix, int row) {
    int n = matrix.size();
    vector<bool> exists(n + 1, false);
    for (auto val : matrix[row]) {
      if (exists[val]) {
        return false;
      }
      exists[val] = true;
    }
    return true;
  }
};