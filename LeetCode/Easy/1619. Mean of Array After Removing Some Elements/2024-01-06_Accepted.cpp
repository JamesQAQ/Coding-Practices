class Solution {
public:
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = arr.size() / 20; i < arr.size() - arr.size() / 20; i++) {
      sum += arr[i];
    }
    return (double)sum / (arr.size() - arr.size() / 10);
  }
};
