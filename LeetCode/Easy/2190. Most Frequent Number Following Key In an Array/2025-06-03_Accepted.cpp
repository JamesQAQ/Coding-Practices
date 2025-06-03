class Solution {
public:
  int mostFrequent(vector<int>& nums, int key) {
    map<int, int> countMap;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == key) {
        int target = nums[i + 1];
        if (countMap.find(target) == countMap.end()) {
          countMap[target] = 0;
        }
        countMap[target]++;
      }
    }

    int ans;
    int maxCount = 0;
    for (auto it : countMap) {
      if (it.second > maxCount) {
        ans = it.first;
        maxCount = it.second;
      }
    }
    return ans;
  }
};
