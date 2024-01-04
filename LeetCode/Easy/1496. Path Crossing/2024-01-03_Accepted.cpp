class Solution {
public:
  bool isPathCrossing(string path) {
    set<pair<int, int>> visited;
    pair<int, int> pos = {0, 0};
    visited.insert(pos);
    for (auto c : path) {
      if (c == 'N') {
        pos.first++;
      } else if (c == 'S') {
        pos.first--;
      } else if (c == 'E') {
        pos.second++;
      } else {
        pos.second--;
      }
      if (visited.find(pos) != visited.end()) {
        return true;
      }
      visited.insert(pos);
    }
    return false;
  }
};
