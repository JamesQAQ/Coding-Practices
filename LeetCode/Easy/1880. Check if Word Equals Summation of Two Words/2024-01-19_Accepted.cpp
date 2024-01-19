class Solution {
public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    return convert(firstWord) + convert(secondWord) == convert(targetWord);
  }

private:
  int convert(string s) {
    int x = 0;
    for (auto c : s) {
      x = x * 10 + c - 'a';
    }
    return x;
  }
};
