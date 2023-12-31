class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<int> prePos(26, -1);
    int ans = -1;
    for (int i = 0; i < s.length(); i++) {
      int val = s[i] - 'a';
      if (prePos[val] != -1) {
        ans = max(ans, i - prePos[val] - 1);
      } else {
        prePos[val] = i;
      }
    }
    return ans;
  }
};
