class Solution {
public:
  int secondHighest(string s) {
    bool isAppeared[10] = {};
    vector<int> digits;
    for (auto c : s) {
      if ('0' <= c && c <= '9') {
        if (!isAppeared[c - '0']) {
          isAppeared[c - '0'] = true;
          digits.push_back(c - '0');
        }
      }
    }
    sort(digits.begin(), digits.end());
    if (digits.size() < 2) {
      return -1;
    }
    return digits[digits.size() - 2];
  }
};
