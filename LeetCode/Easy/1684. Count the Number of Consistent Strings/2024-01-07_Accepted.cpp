class Solution {
public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    vector<bool> isAllowed(26, false);
    for (auto c : allowed) {
      isAllowed[c - 'a'] = true;
    }
    int ans = 0;
    for (auto word : words) {
      ans += isOk(word, isAllowed);
    }
    return ans;
  }

private:
  bool isOk(string word, vector<bool>& isAllowed) {
    for (auto c : word) {
      if (!isAllowed[c - 'a']) {
        return false;
      }
    }
    return true;
  }
};
