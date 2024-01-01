class Solution {
public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<vector<int>> mark(
        matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
      row(matrix, mark, i);
    }
    for (int i = 0; i < matrix[0].size(); i++) {
      col(matrix, mark, i);
    }
    vector<int> result;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (mark[i][j] == 2) {
          result.push_back(matrix[i][j]);
        }
      }
    }
    return result;
  }

private:
  void row(
      vector<vector<int>>& matrix,
      vector<vector<int>>& mark,
      int r) {
    int pos = 0;
    for (int i = 1; i < matrix[r].size(); i++) {
      if (matrix[r][i] < matrix[r][pos]) {
        pos = i;
      }
    }
    mark[r][pos]++;
  }

  void col(
      vector<vector<int>>& matrix,
      vector<vector<int>>& mark,
      int c) {
    int pos = 0;
    for (int i = 1; i < matrix.size(); i++) {
      if (matrix[i][c] > matrix[pos][c]) {
        pos = i;
      }
    }
    mark[pos][c]++;
  }
};
