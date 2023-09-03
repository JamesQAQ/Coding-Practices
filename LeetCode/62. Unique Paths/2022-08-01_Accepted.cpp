class Solution {
public:
  int uniquePaths(int m, int n) {
    if (n > m) {
      swap(n, m);
    }
    long long ans = 1;
    for (int i = 1; i < n; i++) {
      ans *= n + m - i - 1;
      ans /= i;
    }
    return ans;
  }
};
