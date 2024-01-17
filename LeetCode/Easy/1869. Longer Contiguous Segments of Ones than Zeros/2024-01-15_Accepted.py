class Solution:
  def checkZeroOnes(self, s: str) -> bool:
    return max(len(p) for p in s.split('0')) > max(len(p) for p in s.split('1'))
