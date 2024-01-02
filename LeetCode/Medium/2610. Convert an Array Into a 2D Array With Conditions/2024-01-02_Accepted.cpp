class Solution {
public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int pre = -1;
    int rowPos;
    for (auto num : nums) {
      if (num != pre) {
        pre = num;
        rowPos = 0;
      }
      if (rowPos >= result.size()) {
        result.push_back({});
      }
      result[rowPos++].push_back(num);
    }
    return result;
  }
};
