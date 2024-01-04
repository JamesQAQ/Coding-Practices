class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int missing = 0;
    int ptr = 0;
    int cur = 1;
    for (int i = 0; i < arr.size(); i++) {
      while (cur < arr[i]) {
        cur++;
        missing++;
        if (missing == k) {
          return cur - 1;
        }
      }
      cur++;
    }
    while (missing++ < k) {
      cur++;
    }
    return cur - 1;
  }
};
