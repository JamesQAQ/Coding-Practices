class Solution {
public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    map<int, int> count;
    for (int i = 0; i < k; i++) {
      int num = sortedNums[nums.size() - i - 1];
      if (count.find(num) == count.end()) {
        count[num] = 0;
      }
      count[num]++;
    }

    vector<int> result;
    for (auto num : nums) {
      if (count.find(num) != count.end() && count[num] > 0) {
        count[num]--;
        result.push_back(num);
      }
    }
    return result;
  }
};
