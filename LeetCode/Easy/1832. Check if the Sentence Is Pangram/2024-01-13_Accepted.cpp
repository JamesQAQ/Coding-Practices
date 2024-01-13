class Solution {
public:
  bool checkIfPangram(string sentence) {
    bool isAppeared[26] = {};
    for (auto c : sentence) {
      isAppeared[c - 'a'] = true;
    }
    for (int i = 0; i < 26; i++) {
      if (!isAppeared[i]) {
        return false;
      }
    }
    return true;
  }
};
