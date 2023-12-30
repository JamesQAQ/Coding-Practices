class Solution {
public:
  bool makeEqual(vector<string>& words) {
    int count[26] = {};
    for (auto word : words) {
      for (auto c : word) {
        count[c - 'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] % words.size() != 0) {
        return false;
      }
    }
    return true;
  }
};
