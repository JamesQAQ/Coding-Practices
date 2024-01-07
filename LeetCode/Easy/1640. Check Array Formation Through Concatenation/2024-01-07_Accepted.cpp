class Solution {
public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> pos(101, -1);
    for (int i = 0; i < arr.size(); i++) {
      pos[arr[i]] = i;
    }
    for (auto piece : pieces) {
      if (pos[piece[0]] == -1) {
        return false;
      }
      int requiredPos = pos[piece[0]];
      for (auto num : piece) {
        if (pos[num] != requiredPos++) {
          return false;
        }
      }
    }
    return true;
  }
};
