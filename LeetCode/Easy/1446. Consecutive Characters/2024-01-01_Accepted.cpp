class Solution {
public:
  int maxPower(string s) {
    int power = 0;
    int count = 0;
    char pre = '\0';
    for (auto c : s) {
      if (pre != c) {
        power = max(power, count);
        pre = c;
        count = 0;
      }
      count++;
    }
    return max(power, count);
  }
};
