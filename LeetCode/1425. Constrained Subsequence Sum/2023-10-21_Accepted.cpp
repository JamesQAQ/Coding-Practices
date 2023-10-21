class Solution {
public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int ans = nums[0];
    deque<pair<int, int>> q;
    q.push_back({0, nums[0]});
    for (int i = 1; i < nums.size(); i++) {
      while (i - q.front().first > k) {
        q.pop_front();
      }
      int val = max(nums[i], q.front().second + nums[i]);
      while (!q.empty() && val >= q.back().second) {
        q.pop_back();
      }
      q.push_back({i, val});
      ans = max(ans, val);
    }
    return ans;
  }
};
