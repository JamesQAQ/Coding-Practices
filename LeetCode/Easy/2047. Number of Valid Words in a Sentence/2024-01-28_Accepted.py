class Solution:
  def countValidWords(self, sentence: str) -> int:
    ans = 0
    for word in sentence.split(' '):
      if word and self._valid(word):
        ans += 1
    return ans

  def _valid(self, word: str) -> bool:
    hyphen = False
    for i in range(len(word)):
      if word[i] == '-':
        if (hyphen or i == 0 or i == len(word) - 1
            or not word[i - 1].islower() or not word[i + 1].islower()):
          return False
        else:
          hyphen = True
      elif word[i].isdigit():
        return False
      elif word[i] in '!.,' and i != len(word) - 1:
        return False
    return True
