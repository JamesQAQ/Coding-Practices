class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (auto num : grid[i]) {
        if (num < 0) {
          ans++;
        }
      }
    }
    return ans;
  }
};
