class Solution {
public:
  int countPoints(string rings) {
    map<char, int> valueMap;
    valueMap['R'] = 1;
    valueMap['G'] = 2;
    valueMap['B'] = 4;
    vector<int> rods = vector<int>(10, 0);
    for (int i = 0; i < rings.length(); i += 2) {
      rods[rings[i + 1] - '0'] |= valueMap[rings[i]];
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
      if (rods[i] == 7) {
        ans++;
      }
    }
    return ans;
  }
};