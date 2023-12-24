class Solution {
public:
  int minDeletionSize(vector<string>& strs) {
    int n = strs[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!isSorted(strs, i)) {
        ans++;
      }
    }
    return ans;
  }

private:
  bool isSorted(vector<string>& strs, int column) {
    for (int i = 1; i < strs.size(); i++) {
      if (strs[i - 1][column] > strs[i][column]) {
        return false;
      }
    }
    return true;
  }
};
