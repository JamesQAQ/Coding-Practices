class Solution {
public:
  bool checkString(string s) {
    bool existB = false;
    for (auto c : s) {
      if (c == 'b') {
        existB = true;
      } else if (existB) {
        return false;
      }
    }
    return true;
  }
};