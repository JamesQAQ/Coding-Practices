class Solution {
public:
  int minStartValue(vector<int>& nums) {
    int minVal = INT_MAX;
    int sum = 0;
    for (auto num : nums) {
      sum += num;
      minVal = min(minVal, sum);
    }
    if (minVal < 0) {
      return -minVal + 1;
    }
    return 1;
  }
};
