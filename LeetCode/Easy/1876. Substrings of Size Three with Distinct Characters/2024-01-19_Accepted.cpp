class Solution {
public:
  int countGoodSubstrings(string s) {
    int ans = 0;
    for (int i = 0; i < (int)s.length() - 2; i++) {
      ans += (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i]);
    }
    return ans;
  }
};
