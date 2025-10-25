class Solution {
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<bool> isK(nums.size(), false);
    queue<pair<int, int>> que;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == key) {
        que.push({i, k});
      }
    }

    while (!que.empty()) {
      auto top = que.front();
      que.pop();
      isK[top.first] = true;
      if (top.second > 0) {
        if (top.first - 1 >= 0 && !isK[top.first - 1]) {
          que.push({top.first - 1, top.second - 1});
        }
        if (top.first + 1 < nums.size() && !isK[top.first + 1]) {
          que.push({top.first + 1, top.second - 1});
        }
      }
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      if (isK[i]) {
        result.push_back(i);
      }
    }
    return result;
  }
};
