class Solution {
private:
  int _SIZE = 26;

public:
  int countCharacters(vector<string>& words, string chars) {
    int ans = 0;
    vector<int> charsCount = countWords(chars);
    for (auto word : words) {
      if (couldBeFormed(countWords(word), charsCount)) {
        ans += word.length();
      }
    }
    return ans;
  }

private:
  vector<int> countWords(string& s) {
    vector<int> count(_SIZE, 0);
    for (auto c : s) {
      count[c - 'a']++;
    }
    return count;
  }

  bool couldBeFormed(vector<int> wordCount, vector<int>& charsCount) {
    for (int i = 0; i < _SIZE; i++) {
      if (wordCount[i] > charsCount[i]) {
        return false;
      }
    }
    return true;
  }
};
