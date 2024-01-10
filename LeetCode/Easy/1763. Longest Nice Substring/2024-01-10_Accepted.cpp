class Solution {
private:
  bool isAppeared[256] = {};

public:
  string longestNiceSubstring(string s) {
    for (int len = s.length(); len >= 2; len--) {
      for (int i = 0; i + len <= s.length(); i++) {
        if (isNice(s.substr(i, len))) {
          return s.substr(i, len);
        }
      }
    }
    return "";
  }

private:
  bool isNice(string s) {
    for (auto c : s) {
      isAppeared[c] = true;
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
      if (isAppeared[i + 'a'] != isAppeared[i + 'A']) {
        flag = false;
      }
      isAppeared[i + 'a'] = isAppeared[i + 'A'] = false;
    }
    return flag;
  }
};
