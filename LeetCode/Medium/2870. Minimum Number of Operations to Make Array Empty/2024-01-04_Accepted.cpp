class Solution {
public:
  int minOperations(vector<int>& nums) {
    map<int, int> count;
    for (auto num : nums) {
      if (count.find(num) == count.end()) {
        count[num] = 0;
      }
      count[num]++;
    }

    int ans = 0;
    for (auto it : count) {
      if (it.second == 1) {
        return -1;
      }
      ans += (it.second + 2) / 3;
    }
    return ans;
  }
};
