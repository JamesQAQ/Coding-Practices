class Solution {
public:
  int maxNumberOfBalloons(string text) {
    vector<int> count(26, 0);
    for (auto c : text) {
      count[c - 'a']++;
    }
    return min(
        min(min(count[0], count[1]), count[13]),
        min(count[11] / 2, count[14] / 2));
  }
};
