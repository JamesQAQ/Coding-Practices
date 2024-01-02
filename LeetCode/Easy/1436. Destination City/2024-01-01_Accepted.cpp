class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
    set<string> outgoing;
    for (auto path : paths) {
      outgoing.insert(path[0]);
    }
    for (auto path : paths) {
      if (outgoing.find(path[1]) == outgoing.end()) {
        return path[1];
      }
    }
    return "";
  }
};
