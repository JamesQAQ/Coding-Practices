class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    sort(coordinates.begin(), coordinates.end(), cmp);
    int dx = coordinates[1][0] - coordinates[0][0];
    int dy = coordinates[1][1] - coordinates[0][1];
    for (int i = 1; i < coordinates.size() - 1; i++) {
      int x = coordinates[i + 1][0] - coordinates[i][0];
      int y = coordinates[i + 1][1] - coordinates[i][1];
      if (dx * y - dy * x != 0) {
        return false;
      }
    }
    return true;
  }

private:
  static int cmp(vector<int>& i, vector<int>& j) {
    return i[0] < j[0];
  }
};
