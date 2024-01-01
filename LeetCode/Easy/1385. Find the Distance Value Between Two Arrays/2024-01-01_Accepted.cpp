class Solution {
public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int ans = 0;
    for (int i = 0; i < arr1.size(); i++) {
      auto start = lower_bound(arr2.begin(), arr2.end(), arr1[i] - d);
      auto end = upper_bound(arr2.begin(), arr2.end(), arr1[i] + d);
      if (distance(start, end) == 0) {
        ans++;
      }
    }
    return ans;
  }
};
