class Solution {
public:
  int countKDifference(vector<int>& nums, int k) {
    int ans = 0;
    map<int, int> count;
    for (auto num : nums) {
      if (count.find(num) == count.end()) {
        count[num] = 0;
      }
      ans += getFromMap(count, num - k) + getFromMap(count, num + k);
      count[num]++;
    }
    return ans;
  }

private:
  int getFromMap(map<int, int>& count, int num) {
    if (count.find(num) != count.end()) {
      return count[num];
    }
    return 0;
  }
};
