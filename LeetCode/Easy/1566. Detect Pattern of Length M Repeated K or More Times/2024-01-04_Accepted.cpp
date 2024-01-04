class Solution {
public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    int bound = arr.size() - m * k;
    for (int i = 0; i <= bound; i++) {
      if (valid(arr, m, k, i)) {
        return true;
      }
    }
    return false;
  }

private:
  bool valid(vector<int>& arr, int m, int k, int start) {
    for (int i = 0; i < m; i++) {
      int num = arr[start + i];
      for (int j = 1; j < k; j++) {
        if (num != arr[start + j * m + i]) {
          return false;
        }
      }
    }
    return true;
  }
};
