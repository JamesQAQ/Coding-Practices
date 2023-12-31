class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> copiedNums = nums;
    sort(copiedNums.begin(), copiedNums.end());
    map<int, int> mapping;
    int val = 0;
    for (int i = 0; i < copiedNums.size(); i++) {
      if (i) {
        if (copiedNums[i - 1] != copiedNums[i]) {
          val = i;
        }
      }
      mapping[copiedNums[i]] = val;
    }

    vector<int> result;
    for (auto num : nums) {
      result.push_back(mapping[num]);
    }
    return result;
  }
};
