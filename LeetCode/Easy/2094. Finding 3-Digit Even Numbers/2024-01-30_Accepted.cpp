class Solution {
public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> count = vector<int>(10, 0);
    for (auto digit : digits) {
      count[digit]++;
    }
    vector<int> result;
    dfs(0, 0, count, result);
    return result;
  }

private:
  void dfs(int pos, int val, vector<int>& count, vector<int>& result) {
    if (pos == 3) {
      if (val % 2 == 0) {
        result.push_back(val);
      }
      return;
    }
    for (int i = pos ? 0 : 1; i < 10; i++) {
      if (count[i]) {
        count[i]--;
        dfs(pos + 1, val * 10 + i, count, result);
        count[i]++;
      }
    }
  }
};
