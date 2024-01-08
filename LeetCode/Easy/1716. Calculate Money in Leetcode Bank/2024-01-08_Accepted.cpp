class Solution {
public:
  int totalMoney(int n) {
    int weeks = n / 7;
    int remain = n % 7;
    return 28 * weeks + 7 * (weeks - 1) * weeks / 2
        + (1 + remain + 2 * weeks) * remain / 2;
  }
};
