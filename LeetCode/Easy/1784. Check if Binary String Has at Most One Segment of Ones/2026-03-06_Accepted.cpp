class Solution {
public:
  bool checkOnesSegment(string s) {
    bool oneSegmentFound = false;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == '0') {
        oneSegmentFound = true;
      } else if (s[i] == '1' && oneSegmentFound) {
        return false;
      }
    }
    return true;
  }
};
