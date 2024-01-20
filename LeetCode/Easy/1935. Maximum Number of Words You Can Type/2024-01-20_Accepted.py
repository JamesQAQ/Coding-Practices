class Solution:
  def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
    words = text.split(' ')
    ans = 0
    for i in range(0, len(words)):
      if not self._fail(words[i], brokenLetters):
        ans += 1
    return ans

  def _fail(self, word: str, brokenLetters: str) -> bool:
    for brokenLetter in brokenLetters:
      if brokenLetter in word:
        return True
    return False
