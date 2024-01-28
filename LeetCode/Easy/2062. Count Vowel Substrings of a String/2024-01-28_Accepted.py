class Solution:
  def countVowelSubstrings(self, word: str) -> int:
    ans = 0
    for i in range(len(word)):
      for j in range(i, len(word)):
        if self._valid(word[i : j + 1]):
          ans += 1
    return ans

  def _valid(self, s: str) -> bool:
    for c in s:
      if c not in 'aeiou':
        return False
    for c in 'aeiou':
      if c not in s:
        return False
    return True
