class Solution {
public:
  bool checkAlmostEquivalent(string word1, string word2) {
    vector<int> count = vector<int>(26, 0);
    for (auto c : word1) {
      count[c - 'a']++;
    }
    for (auto c : word2) {
      count[c - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (abs(count[i]) > 3) {
        return false;
      }
    }
    return true;
  }
};
