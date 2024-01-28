class Solution {
public:
  int maxLength(vector<string>& arr) {
    vector<int> count(26, 0);
    int ans = 0;
    dfs(0, arr, count, ans);
    return ans;
  }

private:
  void dfs(int x, vector<string>& arr, vector<int>& count, int& ans) {
    if (x == arr.size()) {
      int sum = 0;
      for (auto c : count) {
        if (c >= 2) {
          return;
        }
        sum += c;
      }
      ans = max(ans, sum);
      return;
    }
    for (auto c : arr[x]) {
      count[c - 'a']++;
    }
    dfs(x + 1, arr, count, ans);
    for (auto c : arr[x]) {
      count[c - 'a']--;
    }
    dfs(x + 1, arr, count, ans);
  }
};
