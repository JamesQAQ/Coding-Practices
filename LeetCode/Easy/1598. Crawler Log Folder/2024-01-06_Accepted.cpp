class Solution {
public:
  int minOperations(vector<string>& logs) {
    int ans = 0;
    for (auto log : logs) {
      if (log == "../") {
        if (ans) {
          ans--;
        }
      } else if (log != "./") {
        ans++;
      }
    }
    return ans;
  }
};
