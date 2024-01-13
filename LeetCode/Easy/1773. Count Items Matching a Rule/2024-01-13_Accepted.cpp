class Solution {
public:
  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int idx = 0;
    if (ruleKey != "type") {
      idx = (ruleKey == "color") ? 1 : 2;
    }
    int ans = 0;
    for (auto item : items) {
      ans += (item[idx] == ruleValue);
    }
    return ans;
  }
};
