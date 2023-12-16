class Solution {
public:
  int minExtraChar(string s, vector<string>& dictionary) {
    int len = s.length();
    vector<int> dp(len + 1);
    for (int i = 0; i <= len; i++) {
      dp[i] = i;
    }

    for (int i = 0; i < len; i++) {
      dp[i + 1] = min(dp[i + 1], dp[i] + 1);
      for (int j = 0; j < dictionary.size(); j++) {
        if (match(s, i, dictionary[j])) {
          int to = i + dictionary[j].length();
          dp[to] = min(dp[to], dp[i]);
        }
      }
    }
    return dp[len];
  }

private:
  bool match(string& s, int start, string word) {
    if (start + word.length() > s.length()) {
      return false;
    }
    for (int i = 0; i < word.length(); i++) {
      if (s[start + i] != word[i]) {
        return false;
      }
    }
    return true;
  }
};
