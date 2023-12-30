class Solution:
  def freqAlphabets(self, s: str) -> str:
    for i in range(10, 27):
      encryption = str(i) + '#'
      s = s.replace(encryption, chr(ord('a') + i - 1))
    for i in range(1, 10):
      s = s.replace(str(i), chr(ord('a') + i - 1))
    return s
