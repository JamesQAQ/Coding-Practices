class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    set<int> xAxis;
    for (auto point : points) {
      xAxis.insert(point[0]);
    }
    int ans = 0;
    auto it = xAxis.begin();
    int pre = *it;
    while (++it != xAxis.end()) {
      ans = max(ans, *it - pre);
      pre = *it;
    }
    return ans;
  }
};
