class Solution {
public:
  string shortestPalindrome(string s) {
    int totalLength = s.length();
    int leftFrom = totalLength / 2;
    int rightFrom = totalLength / 2;
    if (totalLength % 2 == 0) {
      leftFrom = leftFrom - 1;
    }
    while (!isPalindrome(s, leftFrom, rightFrom)) {
      totalLength++;
      if (totalLength % 2 == 0) {
        leftFrom--;
      } else {
        rightFrom--;
      }
    }

    int appendLength = totalLength - s.length();
    string appendString = s.substr(s.length() - appendLength, appendLength);
    reverse(appendString.begin(), appendString.end());
    return appendString + s;
  }

private:
  bool isPalindrome(string &s, int leftFrom, int rightFrom) {
    int len = s.length();
    while (leftFrom >= 0) {
      if (s[leftFrom--] != s[rightFrom++]) return false;
    }
    return true;
  }
};