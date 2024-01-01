class Solution {
public:
  int countLargestGroup(int n) {
    vector<int> count(37, 0);
    for (int i = 1; i <= n; i++) {
      count[digits(i)]++;
    }

    int maxCount = 0;
    for (int i = 1; i < 37; i++) {
      maxCount = max(maxCount, count[i]);
    }

    int ans = 0;
    for (int i = 1; i < 37; i++) {
      if (count[i] == maxCount) {
        ans++;
      }
    }
    return ans;
  }

private:
  int digits(int n) {
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
};
