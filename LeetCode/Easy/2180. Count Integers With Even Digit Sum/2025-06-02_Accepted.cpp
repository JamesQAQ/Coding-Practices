class Solution {
public:
  int countEven(int num) {
    int ans = 0;
    for (int i = 1; i <= num; i++) {
      if (isEven(i)) {
        ans++;
      }
    }
    return ans;
  }

private:
  bool isEven(int x) {
    int sum = 0;
    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }
    return sum % 2 == 0;
  }
};