class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) {
      return false;
    }
    vector<int> count1 = countCharacters(word1);
    vector<int> count2 = countCharacters(word2);
    for (int i = 0; i < 26; i++) {
      if (count1[i] && count2[i] == 0) {
        return false;
      }
      if (count2[i] && count1[i] == 0) {
        return false;
      }
    }
    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());
    return count1 == count2;
  }

private:
  vector<int> countCharacters(string s) {
    vector<int> count(26, 0);
    for (auto c : s) {
      count[c - 'a']++;
    }
    return count;
  }
};
