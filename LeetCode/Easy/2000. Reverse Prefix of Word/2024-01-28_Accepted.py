class Solution:
  def reversePrefix(self, word: str, ch: str) -> str:
    pivot = word.find(ch)
    if pivot >= 0:
      prefix = word[:pivot + 1]
      return prefix[::-1] + word[pivot + 1:]
    return word
