class Solution {
  private: int MOD = 1000000007;

  public: int sumSubarrayMins(vector < int > & arr) {
    stack < int > s;
    long long ans = 0;
    for (int i = 0; i < arr.size(); i++) {
      while (!s.empty() && arr[i] < arr[s.top()]) {
        int pos = s.top();
        s.pop();
        ans = (ans + (long long) arr[pos] *
            count(s.empty() ? 0 : s.top() + 1, pos, i - 1)) % MOD;
      }
      s.push(i);
    }
    while (!s.empty()) {
      int pos = s.top();
      s.pop();
      ans = (ans + (long long) arr[pos] *
            count(s.empty() ? 0 : s.top() + 1, pos, arr.size() - 1)) % MOD;
    }
    return ans;
  }

  private: int count(int left, int pos, int right) {
    return _count(left, right) - _count(left, pos - 1) - _count(pos + 1, right);
  }

  int _count(int left, int right) {
    int n = right - left + 1;
    return (1 + n) * n / 2;
  }
};
