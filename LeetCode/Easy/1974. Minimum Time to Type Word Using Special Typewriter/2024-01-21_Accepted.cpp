class Solution {
public:
  int minTimeToType(string word) {
    int ans = word.length();
    word = "a" + word;
    for (int i = 1; i < word.length(); i++) {
      int dis = abs((int)word[i] - word[i - 1]);
      ans += min(dis, 26 - dis);
    }
    return ans;
  }
};
