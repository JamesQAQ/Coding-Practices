class Solution:
  def makeGood(self, s: str) -> str:
    for _ in range(len(s) // 2):
      for i in range(26):
        s = s.replace(chr(i + ord('a')) + chr(i + ord('A')), '')
        s = s.replace(chr(i + ord('A')) + chr(i + ord('a')), '')
    return s
