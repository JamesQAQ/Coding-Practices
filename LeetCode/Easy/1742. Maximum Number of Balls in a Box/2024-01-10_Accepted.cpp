class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    vector<int> count(46, 0);
    for (int i = lowLimit; i <= highLimit; i++) {
      count[sumOfDigits(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= 45; i++) {
      ans = max(ans, count[i]);
    }
    return ans;
  }

private:
  int sumOfDigits(int x) {
    int sum = 0;
    while (x) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
  }
};
