class Solution {
public:
  int minimumSum(int num) {
    vector<int> digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
    }
    stable_sort(digits.begin(), digits.end());
    int ans = INT_MAX;
    for (int i = 0; i < 2; i++) {
      for (int j = i + 1; j < 4; j++) {
        int new1 = digits[i] * 10 + digits[j];
        int new2 = 0;
        for (int k = 0; k < 4; k++) {
          if (k != i && k != j) {
            new2 = new2 * 10 + digits[k];
          }
        }
        ans = min(ans, new1 + new2);
      }
    }
    return ans;
  }
};