class Solution {
public:
  int numSpecial(vector<vector<int>>& mat) {
    int ans = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        ans += isSpecial(mat, i, j);
      }
    }
    return ans;
  }

private:
  vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool isSpecial(vector<vector<int>>& mat, int x, int y) {
    if (mat[x][y] != 1) {
      return false;
    }
    for (auto offset : offsets) {
      int nx = x + offset[0];
      int ny = y + offset[1];
      while (0 <= nx && nx < mat.size() && 0 <= ny && ny < mat[0].size()) {
        if (mat[nx][ny] != 0) {
          return false;
        }
        nx += offset[0];
        ny += offset[1];
      }
    }
    return true;
  }
};
