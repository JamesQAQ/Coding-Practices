class Solution {
public:
  bool areOccurrencesEqual(string s) {
    vector<int> count(26, 0);
    for (auto c : s) {
      count[c - 'a']++;
    }
    int appearTimes = 0;
    for (int i = 0; i < 26; i++) {
      if (count[i]) {
        if (appearTimes == 0) {
          appearTimes = count[i];
        } else if (appearTimes != count[i]) {
          return false;
        }
      }
    }
    return true;
  }
};
