class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    vector<int> count(100, 0);
    for (auto domino : dominoes) {
      if (domino[0] > domino[1]) {
        swap(domino[0], domino[1]);
      }
      count[domino[0] * 10 + domino[1]]++;
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
      ans += (count[i] - 1) * count[i] / 2;
    }
    return ans;
  }
};
