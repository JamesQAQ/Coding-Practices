class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int ans = -1;
    for (int i = 0; i < points.size(); i++) {
      if (points[i][0] == x || points[i][1] == y) {
        if (ans == -1) {
          ans = i;
        } else if (
            abs(points[i][0] - x) + abs(points[i][1] - y)
            < abs(points[ans][0] - x) + abs(points[ans][1] - y)) {
          ans = i;
        }
      }
    }
    return ans;
  }
};
