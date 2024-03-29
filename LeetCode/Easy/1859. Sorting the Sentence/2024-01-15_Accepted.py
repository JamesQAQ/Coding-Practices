class Solution:
  def sortSentence(self, s: str) -> str:
    words = sorted(s.split(' '), key=lambda word: word[-1])
    return ' '.join([word[:-1] for word in words])
