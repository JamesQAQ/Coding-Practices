class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<vector<int>> result(2, vector<int>());
    map<int, int> lose;
    for (auto match : matches) {
      for (int i = 0; i < 2; i++) {
        if (lose.find(match[i]) == lose.end()) {
          lose[match[i]] = 0;
        }
        lose[match[i]] += i;
      }
    }
    for (auto it = lose.begin(); it != lose.end(); it++) {
      if (it->second < 2) {
        result[it->second].push_back(it->first);
      }
    }
    return result;
  }
};
