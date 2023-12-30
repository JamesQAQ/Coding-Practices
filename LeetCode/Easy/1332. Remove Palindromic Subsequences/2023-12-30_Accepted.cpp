class Solution {
public:
  int removePalindromeSub(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] != s[s.length() - i - 1]) {
        return 2;
      }
    }
    return 1;
  }
};
