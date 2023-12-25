class Solution {
public:
  int repeatedNTimes(vector<int>& nums) {
    unordered_map<int, int> count;
    for (auto num : nums) {
      if (count.find(num) == count.end()) {
        count[num] = 0;
      }
      count[num]++;
      if (count[num] == nums.size() / 2) {
        return num;
      }
    }
    return -1;
  }
};
