class Solution {
public:
  int minOperations(string s) {
    string oneStr = "";
    string zeroStr = "";
    int digit = 0;
    for (int i = 0; i < s.length(); i++) {
      oneStr += to_string(1 - digit);
      zeroStr += to_string(digit);
      digit = 1 - digit;
    }
    return min(compare(s, oneStr), compare(s, zeroStr));
  }

private:
  int compare(string& a, string& b) {
    int diff = 0;
    for (int i = 0; i < a.length(); i++) {
      if (a[i] != b[i]) {
        diff++;
      }
    }
    return diff;
  }
};
