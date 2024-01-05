class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    vector<int> result;
    while (result.size() < matrix.size() * matrix[0].size()) {
      for (int i = left; i <= right; i++) {
        result.push_back(matrix[top][i]);
      }
      top++;

      if (top > bottom) {
        break;
      }
      for (int i = top; i <= bottom; i++) {
        result.push_back(matrix[i][right]);
      }
      right--;

      if (left > right) {
        break;
      }
      for (int i = right; i >= left; i--) {
        result.push_back(matrix[bottom][i]);
      }
      bottom--;

      if (top > bottom) {
        break;
      }
      for (int i = bottom; i >= top; i--) {
        result.push_back(matrix[i][left]);
      }
      left++;
    }
    return result;
  }
};
