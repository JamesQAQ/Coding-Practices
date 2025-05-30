class Solution {
public:
  string firstPalindrome(vector<string>& words) {
    for (auto word : words) {
      if (isPalindromic(word)) {
        return word;
      }
    }
    return "";
  }

private:
  bool isPalindromic(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] != s[s.length() - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};