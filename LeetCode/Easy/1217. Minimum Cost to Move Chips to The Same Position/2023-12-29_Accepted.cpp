class Solution {
public:
  int minCostToMoveChips(vector<int>& position) {
    vector<int> count(2, 0);
    for (int i = 0; i < position.size(); i++) {
      count[position[i] % 2]++;
    }
    return min(count[0], count[1]);
  }
};
