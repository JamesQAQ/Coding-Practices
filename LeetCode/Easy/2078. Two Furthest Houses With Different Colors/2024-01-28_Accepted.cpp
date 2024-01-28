class Solution {
public:
  int maxDistance(vector<int>& colors) {
    vector<bool> appeared = vector<bool>(101, false);
    vector<int> indexes;
    int ans = 0;
    for (int i = 0; i < colors.size(); i++) {
      for (auto idx : indexes) {
        if (colors[idx] != colors[i]) {
          ans = max(ans, i - idx);
        }
      }
      if (!appeared[colors[i]]) {
        appeared[colors[i]];
        indexes.push_back(i);
      }
    }
    return ans;
  }
};
