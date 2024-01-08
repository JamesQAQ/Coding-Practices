class Solution {
public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    int maxLen = 0;
    int ans = 0;
    for (auto rect : rectangles) {
      int sqr = min(rect[0], rect[1]);
      if (sqr > maxLen) {
        maxLen = sqr;
        ans = 1;
      } else if (sqr == maxLen) {
        ans++;
      }
    }
    return ans;
  }
};
