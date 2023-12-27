class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    string s = str1 + str2;
    int g = gcd(str1.length(), str2.length());
    for (int i = g; i >= 1; i--) {
      if (g % i == 0 && isOk(s, i)) {
        return s.substr(0, i);
      }
    }
    return "";
  }

private:
  int gcd(int m, int n) {
    while (n) {
      int tmp = n;
      n = m % n;
      m = tmp;
    }
    return m;
  }

  bool isOk(string s, int len) {
    for (int i = 0; i < len; i++) {
      char c = s[i];
      for (int j = i + len; j < s.length(); j += len) {
        if (s[j] != c) {
          return false;
        }
      }
    }
    return true;
  }
};
