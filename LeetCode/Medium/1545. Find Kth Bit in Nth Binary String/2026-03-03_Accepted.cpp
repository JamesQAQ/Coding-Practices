class Solution {
public:
  char findKthBit(int n, int k) {
    return '0' + dfs(n, k - 1);
  }

  int dfs(int n, int k) {
    if (n == 1) {
      return 0;
    }
    int len = (1 << n) - 1;
    if (k == len / 2) {
      return 1;
    } else if (k < len / 2) {
      return dfs(n - 1, k);
    }
    return 1 - dfs(n - 1, len - 1 - k);
  }
};
