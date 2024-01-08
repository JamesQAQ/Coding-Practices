class Solution {
public:
  vector<int> decode(vector<int>& encoded, int first) {
    vector<int> result;
    result.push_back(first);
    int cur = first;
    for (auto num : encoded) {
      cur ^= num;
      result.push_back(cur);
    }
    return result;
  }
};
