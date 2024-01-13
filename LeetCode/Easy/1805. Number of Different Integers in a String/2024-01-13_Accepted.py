class Solution:
  def numDifferentIntegers(self, word: str) -> int:
    parts = word.translate(
        str.maketrans(string.ascii_lowercase, ' ' * 26)).split(' ')
    numSet = {}
    for part in parts:
      if part:
        numSet[int(part)] = True
    return len(numSet)
