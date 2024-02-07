class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> partition;
    dfs(s, partition, result);
    return result;
  }

private:
  void dfs(
      string s,
      vector<string>& partition,
      vector<vector<string>>& result) {
    if (s == "") {
      result.push_back(partition);
      return;
    }
    for (int i = 1; i <= s.length(); i++) {
      if (isPalindrome(s.substr(0, i))) {
        partition.push_back(s.substr(0, i));
        dfs(s.substr(i, s.length() - i), partition, result);
        partition.pop_back();
      }
    }
  }

  bool isPalindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] != s[s.length() - i - 1]) {
        return false;
      }
    }
    return true;
  }
};
