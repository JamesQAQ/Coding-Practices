class Solution {
public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int i = 0; i < 4; i++) {
      mat = rotate(mat);
      if (mat == target) {
        return true;
      }
    }
    return false;
  }

private:
  bool compare(vector<vector<int>>& a, vector<vector<int>>& b) {
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < a[0].size(); j++) {
        if (a[i][j] != b[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  vector<vector<int>> rotate(vector<vector<int>>& mat) {
    vector<vector<int>> newMat(mat.size(), vector<int>(mat[0].size()));
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        newMat[j][mat[0].size() - i - 1] = mat[i][j];
      }
    }
    return newMat;
  }
};
