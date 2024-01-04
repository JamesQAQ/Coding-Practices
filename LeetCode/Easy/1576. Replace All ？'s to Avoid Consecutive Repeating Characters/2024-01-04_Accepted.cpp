class Solution {
public:
  string modifyString(string s) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '?') {
        s[i] = replacement(s, i);
      }
    }
    return s;
  }

private:
  char replacement(string& s, int pos) {
    for (int i = 0; i < 26; i++) {
      if (pos > 0 && s[pos - 1] == 'a' + i) {
        continue;
      }
      if (pos < s.length() - 1 && s[pos + 1] == 'a' + i) {
        continue;
      }
      return 'a' + i;
    }
    return '\0';
  }
};
