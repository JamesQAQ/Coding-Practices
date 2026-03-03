class Solution {
public:
  int countHillValley(vector<int>& nums) {
    vector<int> processedNums;
    processedNums.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        processedNums.push_back(nums[i]);
      }
    }
    
    int ans = 0;
    for (int i = 1; i < processedNums.size() - 1; i++) {
      if ((processedNums[i - 1] > processedNums[i]
           && processedNums[i] < processedNums[i + 1])
          || (processedNums[i - 1] < processedNums[i]
              && processedNums[i] > processedNums[i + 1])) {
        ans++;
      }
    }
    return ans;
  }
};
