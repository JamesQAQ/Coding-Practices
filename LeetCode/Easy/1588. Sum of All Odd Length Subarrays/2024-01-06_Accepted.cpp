class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    vector<int> sum(arr.size());
    sum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      sum[i] = sum[i - 1] + arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= arr.size(); i += 2) {
      for (int j = 0; j + i - 1 < arr.size(); j++) {
        ans += sum[j + i - 1];
        if (j > 0) {
          ans -= sum[j - 1];
        }
      }
    }
    return ans;
  }
};
