class Solution {
public:
  int countTriples(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int left = j * j - i * i;
        int k = ceil(sqrt(left));
        if (k * k == left) {
          ans++;
        }
      }
    }
    return ans;
  }
};
