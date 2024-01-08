class Solution {
public:
  bool halvesAreAlike(string s) {
    vector<bool> isVowel(123, false);
    string vowels = "aeiouAEIOU";
    for (auto vowel : vowels) {
      isVowel[vowel] = true;
    }
    return count(s.substr(0, s.length() / 2), isVowel)
        == count(s.substr(s.length() / 2, s.length() / 2), isVowel);
  }

private:
  int count(string s, vector<bool>& isVowel) {
    int sum = 0;
    for (auto c : s) {
      sum += (isVowel[c]);
    }
    return sum;
  }
};
