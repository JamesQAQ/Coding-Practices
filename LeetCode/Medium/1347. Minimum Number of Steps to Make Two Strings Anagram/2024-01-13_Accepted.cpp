class Solution {
public:
  int minSteps(string s, string t) {
    vector<int> countS = countCharacters(s);
    vector<int> countT = countCharacters(t);
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += abs(countS[i] - countT[i]);
    }
    return ans / 2;
  }

private:
  vector<int> countCharacters(string& s) {
    vector<int> count(26, 0);
    for (auto c : s) {
      count[c - 'a']++;
    }
    return count;
  }
};
