class Solution {
public:
  int maxScore(string s) {
    int lsum = (s[0] == '0');
    int rsum = 0;
    for (int i = 1; i < s.length(); i++) {
      rsum += (s[i] == '1');
    }
    int ans = lsum + rsum;
    for (int i = 1; i < s.length() - 1; i++) {
      if (s[i] == '0') {
        lsum++;
      } else {
        rsum--;
      }
      ans = max(ans, lsum + rsum);
    }
    return ans;
  }
};
