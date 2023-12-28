class Solution {
public:
  int balancedStringSplit(string s) {
    int ans = 0;
    char cur;
    int count = 0;
    for (auto c : s) {
      if (count == 0) {
        cur = c;
        count++;
      } else if (cur == c) {
        count++;
      } else {
        count--;
        if (count == 0) {
          ans++;
        }
      }
    }
    return ans;
  }
};
